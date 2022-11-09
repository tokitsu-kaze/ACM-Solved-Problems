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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll v[MAX];
vector<ll> mp[MAX];
bool flag[MAX];
ll bfs(ll x)
{
	ll i,res=v[x];
	queue<ll> q;
	q.push(x);
	flag[x]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<sz(mp[x]);i++)
		{
			if(!flag[mp[x][i]])
			{
				flag[mp[x][i]]=1;
				q.push(mp[x][i]);
				res=min(res,v[mp[x][i]]);
			}
		}
	}
	return res;
}
int main()
{
	ll n,i,m,a,b,ans;
	while(~scanf("%lld%lld",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&v[i]);
			mp[i].clear();
			flag[i]=0;
		}
		while(m--)
		{
			scanf("%lld%lld",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				ans+=bfs(i);
	//			cout<<i<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}