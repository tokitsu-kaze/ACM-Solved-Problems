#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4e3+10;
const int mod=998244353;
struct Discretization
{
	#define type int
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
}dx,dy;
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
ll inv(ll x){return qpow(x,mod-2);}
int comb[MAX][MAX];
void init_comb(int n,int m)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=i;j++)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
			if(comb[i][j]>=mod) comb[i][j]-=mod;
		}
	}
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
struct node{int x,y;}a[MAX],b[MAX];
int cnt[MAX][MAX];
ll sum[MAX];
int main()
{
	int n,i,j,k,x1,y1,x2,y2;
	ll fm,ans;
	init_comb(MAX-10,MAX-10);
	scanf("%d",&n);
	dx.init();
	dy.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
		dx.add(a[i].x);
		dx.add(b[i].x);
		dy.add(a[i].y);
		dy.add(b[i].y);
	}
	dx.work();
	dy.work();
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		x1=dx.get_pos(a[i].x);
		x2=dx.get_pos(b[i].x);
		y1=dy.get_pos(a[i].y);
		y2=dy.get_pos(b[i].y);
		cnt[x1][y1]++;
		cnt[x1][y2]--;
		cnt[x2][y1]--;
		cnt[x2][y2]++;
	}
	memset(sum,0,sizeof sum);
	for(i=1;i<dx.size();i++)
	{
		for(j=1;j<dy.size();j++)
		{
			cnt[i][j]+=cnt[i][j-1]+cnt[i-1][j]-cnt[i-1][j-1];
			sum[cnt[i][j]]+=1LL*(dx.get_val(i+1)-dx.get_val(i))*
								(dy.get_val(j+1)-dy.get_val(j));
		}
	}
	for(i=1;i<=n;i++) sum[i]%=mod;
	for(k=1;k<=n;k++)
	{
		fm=inv(C(n,k));
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans=(ans+(1-C(n-i,k)*fm)%mod*sum[i])%mod;
			if(ans<0) ans+=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
