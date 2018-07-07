#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=3e3+10;
const ll mod=1e9+7;
namespace polysum {
	#define rep(i,a,n) for (int i=a;i<n;i++)
	#define per(i,a,n) for (int i=n-1;i>=a;i--)
	const int D=101000;
	ll a[D],f[D],g[D],p[D],p1[D],p2[D],b[D],h[D][2],C[D];
	ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
	ll calcn(int d,ll *a,ll n) { // a[0].. a[d]  a[n] 
		if (n<=d) return a[n];
		p1[0]=p2[0]=1;
		rep(i,0,d+1) {
			ll t=(n-i+mod)%mod;
			p1[i+1]=p1[i]*t%mod;
		}
		rep(i,0,d+1) {
			ll t=(n-d+i+mod)%mod;
			p2[i+1]=p2[i]*t%mod;
		}
		ll ans=0;
		rep(i,0,d+1) {
			ll t=g[i]*g[d-i]%mod*p1[i]%mod*p2[d-i]%mod*a[i]%mod;
			if ((d-i)&1) ans=(ans-t+mod)%mod;
			else ans=(ans+t)%mod;
		}
		return ans;
	}
	void init(int M) {
		f[0]=f[1]=g[0]=g[1]=1;
		rep(i,2,M+5) f[i]=f[i-1]*i%mod;
		g[M+4]=powmod(f[M+4],mod-2);
		per(i,1,M+4) g[i]=g[i+1]*(i+1)%mod;
	}
	ll polysum(ll n,ll *a,ll m) { // a[0].. a[m] \sum_{i=0}^{n-1} a[i]
		a[m+1]=calcn(m,a,m+1);
		rep(i,1,m+2) a[i]=(a[i-1]+a[i])%mod;
		return calcn(m+1,a,n-1);
	}
	ll qpolysum(ll R,ll n,ll *a,ll m) { // a[0].. a[m] \sum_{i=0}^{n-1} a[i]*R^i
		if (R==1) return polysum(n,a,m);
		a[m+1]=calcn(m,a,m+1);
		ll r=powmod(R,mod-2),p3=0,p4=0,c,ans;
		h[0][0]=0;h[0][1]=1;
		rep(i,1,m+2) {
			h[i][0]=(h[i-1][0]+a[i-1])*r%mod;
			h[i][1]=h[i-1][1]*r%mod;
		}
		rep(i,0,m+2) {
			ll t=g[i]*g[m+1-i]%mod;
			if (i&1) p3=((p3-h[i][0]*t)%mod+mod)%mod,p4=((p4-h[i][1]*t)%mod+mod)%mod;
			else p3=(p3+h[i][0]*t)%mod,p4=(p4+h[i][1]*t)%mod;
		}
		c=powmod(p4,mod-2)*(mod-p3)%mod;
		rep(i,0,m+2) h[i][0]=(h[i][0]+h[i][1]*c)%mod;
		rep(i,0,m+2) C[i]=h[i][0];
		ans=(calcn(m,C,n)*powmod(R,n)-c)%mod;
		if (ans<0) ans+=mod;
		return ans;
	}
}// polysum::init();
ll dp[MAX][MAX];
VI mp[MAX];
int main()
{
	int n,d,i,x;
	polysum::init(3030);
	while(~scanf("%d%d",&n,&d))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x].pb(i);
		}
		function<void(int)> dfs=[&](int x)
		{
			ll tmp;
			for(i=1;i<=n+1;i++) dp[x][i]=1;
			dp[x][0]=0;
			for(auto to:mp[x])
			{
				dfs(to);
				tmp=0;
				for(i=1;i<=n+1;i++)
				{
					(tmp+=dp[to][i])%=mod;
					(dp[x][i]*=tmp)%=mod;
				}
			}
		};
		dfs(1);
		for(i=1;i<=n+1;i++) (dp[1][i]+=dp[1][i-1])%=mod;
		printf("%lld\n",polysum::calcn(n,dp[1]+1,d-1));
	}
	return 0;
} 
