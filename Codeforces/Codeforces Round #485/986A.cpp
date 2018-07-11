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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX],col[111],s[MAX];
int flag[MAX];
struct node
{
	int x,d;
};
void bfs(int c)
{
	int i;
	node to,t;
	queue<node> q;
	mem(flag,0);
	for(i=0;i<sz(col[c]);i++)
	{
		q.push(node{col[c][i],0});
		flag[col[c][i]]=1;
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		s[t.x].pb(t.d);
		for(i=0;i<sz(mp[t.x]);i++)
		{
			if(!flag[mp[t.x][i]])
			{
				flag[mp[t.x][i]]=1;
				q.push(node{mp[t.x][i],t.d+1});
			}
		}
	}
}
int main()
{
	int n,m,ss,k,i,j,a,b,c;
	ll ans;
	while(~scanf("%d%d%d%d",&n,&m,&k,&ss))
	{
		for(i=1;i<=n;i++) mp[i].clear(),s[i].clear();
		for(i=1;i<=k;i++) col[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c);
			col[c].pb(i);
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		for(i=1;i<=k;i++) bfs(i);
		for(i=1;i<=n;i++)
		{
			ans=0;
			j=0;
			sort(all(s[i]));
			for(j=0;j<ss;j++) ans+=s[i][j];
			printf("%lld%c",ans," \n"[i==n]);
		}
	}
	return 0;
}