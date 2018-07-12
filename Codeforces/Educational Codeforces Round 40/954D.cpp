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
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> mp[1011];
int dis[2][1011];
void bfs(int s,int f)
{
	int i,t,to;
	queue<int> q;
	q.push(s);
	dis[f][s]=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<sz(mp[t]);i++)
		{
			to=mp[t][i];
			if(dis[f][to]>=dis[f][t]+1)
			{
				dis[f][to]=dis[f][t]+1;
				q.push(to);
			}
		}
	}
}
int main()
{
	int n,m,s,t,a,b,i,j,ans;
	while(~scanf("%d%d%d%d",&n,&m,&s,&t))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		mem(dis,0x3f);
		bfs(s,0);
		bfs(t,1);
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(dis[0][i]+1+dis[1][j]>=dis[0][t]&&dis[1][i]+1+dis[0][j]>=dis[0][t]) ans++;
			}
		}
		printf("%d\n",ans-m);
	}
	return 0;
}