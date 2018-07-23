#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e6+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
struct FastIO  
{  
	static const int S=200;  
	int wpos;  
	char wbuf[S];  
	FastIO():wpos(0){}  
	inline int xchar()  
	{  
		static char buf[S];  
		static int len=0,pos=0;  
		if(pos==len) pos=0,len=fread(buf,1,S,stdin);  
		if(pos==len) exit(0);  
		return buf[pos++];  
	}  
	inline int read()  
	{  
		int s=1,c=xchar(),x=0;  
		while(c<=32) c=xchar();  
		if(c=='-') s=-1,c=xchar();  
		for(;'0'<=c&&c<='9';c=xchar()) x=x*10+c-'0';  
		return x*s;  
	}  
	~FastIO()  
	{  
		if(wpos) fwrite(wbuf,1,wpos,stdout),wpos=0;  
	}  
}io;
int v[MAX],maxx[MAX][22];
int pmax(int a,int b)
{
	if(v[a]==v[b]) return min(a,b);
	return v[a]>v[b]?a:b;
}
void RMQ(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		maxx[i][0]=i;
		for(j=1;1<<(j-1)<=n;j++)
		{
			maxx[i][j]=0;
		}
	}
	for(j=1;1<<(j-1)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			int t=1<<(j-1);
			maxx[i][j]=pmax(maxx[i][j-1],maxx[i+t][j-1]);
		}
	}
}
int query(int l,int r)
{
	int j=(int)(log10(r-l+1)/log10(2))+1;
	int i=r-(1<<(j-1))+1;
	return pmax(maxx[l][j-1],maxx[i][j-1]);
}
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x)
{
	return pow2(x,mod-2);
}
ll fac[MAX],invfac[MAX];
void init(int n)
{
	ll i;
	fac[0]=invfac[0]=1;
	for(i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		invfac[i]=inv(fac[i]);
	}
}
ll C(int n,int m)
{
	if(m>n||m<0) return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
namespace DFS
{
	struct node{int l,r;};
	int top;
	node st[MAX];
	ll dfs(int mn,int mx)
	{
		ll res=1;
		int l,r;
		l=mn;
		r=mx;
		top=0;
		st[top].l=l;
		st[top++].r=r;
		while(top)
		{
			l=st[top-1].l;
			r=st[--top].r;
			if(l>=r) continue;
			int pos=query(l,r);
			res=res*C(r-l,pos-l)%mod;
			st[top].l=l;
			st[top++].r=pos-1;
			st[top].l=pos+1;
			st[top++].r=r;
		}
		return res;
	}
}
ll dfs(int l,int r)
{
	if(l>=r) return 1LL;
	int pos=query(l,r);
	return dfs(l,pos-1)*dfs(pos+1,r)%mod*C(r-l,pos-l)%mod;
}
int main()
{
	int n,t,i;
//	scanf("%d",&t);
	t=io.read();
	init(MAX-10);
	ll ans;
	while(t--)
	{
//		scanf("%d",&n);
		n=io.read();
		for(i=1;i<=n;i++) v[i]=io.read();//scanf("%d",&v[i]);
		RMQ(n);
		ans=DFS::dfs(1,n)*invfac[n]%mod*n%mod*inv(2)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
