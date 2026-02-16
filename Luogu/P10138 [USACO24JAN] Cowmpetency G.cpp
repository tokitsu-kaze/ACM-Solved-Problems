#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
const int mod=1e9+7;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int a[105],h[105],s[505];
ll dp[2][MAX],sum[2][MAX];
int add(int l,int r,int v)
{
	int i;
	l=d.get_pos(l);
	r=d.get_pos(r);
	for(i=l;i<=r;i++)
	{
		if(s[i]!=0 && s[i]!=v) return 0;
		s[i]=v;
	}
	return 1;
}
int main()
{
	int n,q,c,i,j,ok,pre,len,x,f;
	scanf("%d%d%d",&n,&q,&c);
	d.init();
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&a[i],&h[i]);
		d.add(a[i]);
		d.add(a[i]+1);
		d.add(h[i]-1);
		d.add(h[i]);
		if(h[i]+1<=n) d.add(h[i]+1);
	}
	d.add(n);
	d.work();
	n=d.size();
	memset(s,0,sizeof s);
	ok=1;
	for(i=1;i<=q;i++)
	{
		ok&=add(a[i]+1,h[i]-1,-1);
		ok&=add(h[i],h[i],1);
	}
	if(!ok)
	{
		puts("0");
		return 0;
	}
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	sum[f][0]=dp[f][0]=1;
	for(j=1;j<=c;j++) sum[f][j]=(sum[f][j-1]+dp[f][j])%mod;
	pre=0;
	for(i=1;i<=n;i++)
	{
		x=d.get_val(i);
		len=x-pre;
//		printf("%d %d %d\n",x,len,s[i]);
		f^=1;
		sum[f][0]=0;
		for(j=1;j<=c;j++)
		{
			if(s[i]==-1) dp[f][j]=dp[!f][j]*qpow(j,len)%mod;
			else if(s[i]==1) dp[f][j]=sum[!f][j-1];
			else dp[f][j]=((qpow(j,len)-qpow(j-1,len)+mod)*sum[!f][j-1]
						 +dp[!f][j]*qpow(j,len))%mod;
			sum[f][j]=(sum[f][j-1]+dp[f][j])%mod;
		}
		pre=x;
	}
	printf("%lld\n",sum[f][c]);
	return 0;
}
/*
考虑dp[i][j]表示考虑了1..i，第i个数是j的方案数。
发现当限制有包含关系的时候无法转移。
因为限制跟前缀max有关，所以不用考虑每个数是啥，
直接考虑前缀max是啥。
dp[i][j]表示1..i前缀max为j的方案数。
先把限制弄到每个点上，每个点有3种可能的状态：
-1:不可能是严格前缀max，ai=1..j，dp[i][j]=dp[i-1][j]*j；
1:一定是，ai=j，dp[i][j]=sum{dp[i-1][k] k=1..j-1}；
0:可能是，1和-1都抄一遍。
对于限制(a,h)，[a+1,h-1]是-1，[h,h]是1
由于n=1e9，所以还需要离散化。离散化后可以O(q^2)暴力搞状态。
再考虑离散化后的转移：
-1:dp[i][j]=dp[i-1][j]*(j^len)
1:不变
0: -1 直接抄过来，1的部分，考虑实际意义，至少要填一个j，所以
dp[i][j]=(j^len-(j-1)^len)*sum{dp[i-1][k] k=1..j-1}
*/
