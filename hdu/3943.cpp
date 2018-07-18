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
const ll mod=998244353;
/****************************************  head  ****************************************/
ll dp[22][22][22];
ll gao(ll x,ll y,ll z)
{
	const int base=10;
	int p[33],tot=0;
	if(x==-1) return 0;
	while(1)
	{
		p[tot++]=x%base;
		x/=base;
		if(!x) break;
	}
	function<ll(int,int,int,int,int)> dfs=[&](int pos,int lead,int a,int b,int limt)->ll
	{
		if(a>y||b>z) return 0;
		if(pos==-1) return a==y&&b==z;
		if(!limt&&!lead&&dp[pos][a][b]!=-1) return dp[pos][a][b];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,a+(i==4),b+(i==7),limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[pos][a][b]=res;
		return res;
	};
	return dfs(tot-1,1,0,0,1);
}
int main()
{
	int t,cas=1,n;
	scanf("%d",&t);
	ll p,q,x,y,z;
	while(t--)
	{
		mem(dp,-1);
		scanf("%lld%lld%lld%lld",&p,&q,&x,&y);
		scanf("%d",&n);
		printf("Case #%d:\n",cas++);
		while(n--)
		{
			scanf("%lld",&z);
			z+=gao(p,x,y);
			ll l,r,mid;
			l=p;
			r=q;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(gao(mid,x,y)<z) l=mid+1;
				else r=mid;
			}
			if(gao(l,x,y)!=z) puts("Nya!");
			else printf("%lld\n",l);
		}
	}
	return 0;
}
