#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8e5+10;
struct Dijkstra
{
	#define type int
	const type inf=INF;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=MAX;
	vector<node> mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	void work(int s)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=0;
		q.push({s,type(0)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id]) continue;
			vis[t.id]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.v;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					if(!vis[to]) q.push({to,dis[to]});
				}
			}
		}
	}
	#undef type
}dij;
char s[MAX];
void add_edge(int a,int b,int x,
			  int c,int d,int y,
			  int w,vector<vector<int>>& id)
{
	dij.add_edge(id[a][b]+x,id[c][d]+y,w);
	dij.add_edge(id[c][d]+y,id[a][b]+x,w);
}
int main()
{
	int T,n,m,i,j,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		vector<vector<int>> id(n+2,vector<int>(m+2,0));
		vector<string> mp;
		mp.push_back("");
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			mp.push_back(" "+string(s));
		}
		tot=1;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				id[i][j]=tot;
				tot+=2;
			}
		}
		dij.init(tot+2);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				// right=0, down=1
				add_edge(i,j-1,0,i,j,0,mp[i][j]!='A',id);
				add_edge(i-1,j,1,i,j,1,mp[i][j]!='A',id);
				add_edge(i,j-1,0,i,j,1,mp[i][j]!='B',id);
				add_edge(i-1,j,1,i,j,0,mp[i][j]!='B',id);
				add_edge(i,j-1,0,i-1,j,1,mp[i][j]!='C',id);
				add_edge(i,j,1,i,j,0,mp[i][j]!='C',id);
			}
		}
		dij.work(id[1][0]+0);
		printf("%d\n",dij.dis[id[n][m]+0]);
	}
	return 0;
}
