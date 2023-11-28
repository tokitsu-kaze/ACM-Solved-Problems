#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const int MAX=6e5+10;
const ll mod=1e9+7;
int v[1010];
vector<int> mp[1010];
void dfs(int x)
{
	int i,to;
	for(i=0;i<sz(mp[x]);i++)
	{
		int to=mp[x][i];
		if(v[x]+1<v[to])
		{
			v[to]=v[x]+1;
			dfs(to);
		}
	}
}
int main()
{
	int i,n,h,m,bad[1010],a,b;
	while(~scanf("%d%d%d",&n,&h,&m))
	{
		mem(v,0x3f);
		for(i=0;i<h;i++)
		{
			scanf("%d",&bad[i]);
			v[bad[i]]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		for(i=0;i<h;i++) dfs(bad[i]);
		int ans=*max_element(v,v+n);
		for(i=0;i<n;i++)
		{
			if(v[i]==ans)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}