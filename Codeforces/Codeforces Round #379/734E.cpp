#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
int v[MAX],s,ans,belong[MAX],flag[MAX];
vector<int> mp[MAX],res[MAX];
void dfs1(int x,int pre,int c,int id)
{
	int i,to;
	if(v[x]!=c) return;
	if(flag[x]) return;
	belong[x]=id;
	flag[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs1(to,x,c,id);
	}
}
void dfs2(int x,int pre,int h)
{
	int i,to;
	if(flag[x]) return;
	flag[x]=1;
	for(i=0;i<sz(res[x]);i++)
	{
		to=res[x][i];
		if(to==pre) continue;
		dfs2(to,x,h+1);
	}
	if(h>ans)
	{
		ans=h;
		s=x;
	}
}
int main()
{
	int n,i,j,a,b,tot;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			mp[i].clear();
			res[i].clear();
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		s=0;
		mem(belong,0);
		mem(flag,0);
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) dfs1(i,0,v[i],++tot);
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<sz(mp[i]);j++)
			{
				if(belong[i]!=belong[mp[i][j]])
				{
					res[belong[i]].pb(belong[mp[i][j]]);
					res[belong[mp[i][j]]].pb(belong[i]);
				}
			}
		}
		ans=0;
		s=1;
		mem(flag,0);
		dfs2(s,0,1);
		ans=0;
		mem(flag,0);
		dfs2(s,0,1);
		printf("%d\n",ans/2);
	}
	return 0;
}