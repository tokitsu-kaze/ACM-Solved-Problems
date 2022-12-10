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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e6+10;
const ll mod=1e9+7;
ll fac[22];
ll init()
{
	ll i,j;
	for(i=1;i<=18;i++)
	{
		fac[i]=1;
		for(j=1;j<=i;j++)
		{
			fac[i]*=j;
		}
	}
}
vector<ll> a,b;
ll n,k,s,l,x,ans;
map<ll,map<ll,ll> > mp;
void dfs1(int pos,ll cnt,ll now)
{
	if(now>s) return;
	if(cnt>k) return;
	if(pos==sz(a))
	{
		mp[now][cnt]++;
		return;
	}
	dfs1(pos+1,cnt,now+a[pos]);
	if(a[pos]<19) dfs1(pos+1,cnt+1,now+fac[a[pos]]);
	dfs1(pos+1,cnt,now);
}
void dfs2(int pos,ll cnt,ll now)
{
	if(now>s) return;
	if(cnt>k) return;
	if(pos==sz(b))
	{
		for(ll i=0;i<=k-cnt;i++) ans+=mp[s-now][i];
		return;
	}
	dfs2(pos+1,cnt,now+b[pos]);
	if(b[pos]<19) dfs2(pos+1,cnt+1,now+fac[b[pos]]);
	dfs2(pos+1,cnt,now);
}
int main()
{
	int i;
	init();
	while(~scanf("%lld%lld%lld",&n,&k,&s))
	{
		a.clear();
		b.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			if(i&1) a.pb(x);
			else b.pb(x);
		}
		mp.clear();
		ans=0;
		dfs1(0,0,0);
		dfs2(0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}