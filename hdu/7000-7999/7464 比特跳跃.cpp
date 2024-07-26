#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
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
ll dp[MAX];
void sosdp(int n,int k)
{
	int i,j,s;
	s=0;
	while((1<<s)<=n) s++;
	for(i=0;i<(1<<s);i++) dp[i]=LLINF;
	for(j=0;j<s;j++)
	{
		for(i=0;i<(1<<s);i++)
		{
			if(!((i>>j)&1))
			{
				dp[i^(1<<j)]=min(dp[i^(1<<j)],
						dij.dis[i]+1LL*k*(i^(1<<j)));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n,m,k,i,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		dij.init(n);
		while(m--)
		{
			cin>>a>>b>>c;
			dij.add_edge(a,b,c);
			dij.add_edge(b,a,c);
		}
		dij.work(1);
		sosdp(n,k);
		for(i=2;i<=n;i++) dij.add_edge(1,i,min(dp[i],1LL*k*(1|i)));
		dij.work(1);
		for(i=2;i<=n;i++) cout<<dij.dis[i]<<" \n"[i==n];
	}
	return 0;
}
