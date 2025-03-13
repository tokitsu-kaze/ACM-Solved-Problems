#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=2e5+10;
struct Minimum_Steiner_Tree
{
	#define type ll
	const type inf=LLINF;
	static const int N=88;
	static const int K=11;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	type mp[N][N];
	type dp[(1<<K)+3][N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
	}
	void dijkstra(int s)
	{
		int i,j,x,to;
		type mn,w;
		priority_queue<node> q;
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
			if(dp[s][i]!=inf) q.push({i,dp[s][i]});
		}
		for(i=1;i<=n;i++)
		{
			x=0;
			mn=inf;
			for(j=1;j<=n;j++)
			{
				if(!vis[j]&&dp[s][j]<mn)
				{
					x=j;
					mn=dp[s][j];
				}
			}
			if(mn==inf) return;
			vis[x]=1;
			for(j=1;j<=n;j++)
			{
				to=j;
				w=mp[x][j];
				dp[s][to]=min(dp[s][to],dp[s][x]+w);
			}
		}
	}
	type ans[N][N];
	void work(vector<int> key_node)
	{
		int s,t,i,k,x;
		type res;
		k=key_node.size();
		for(s=0;s<(1<<k);s++)
		{
			for(i=1;i<=n;i++) dp[s][i]=inf;
		}
		for(i=0;i<k;i++) dp[(1<<i)][key_node[i]]=0;
		for(s=0;s<(1<<k);s++)
		{
			for(t=s&(s-1);t;t=s&(t-1))
			{
				if(t<(s^t)) break;
				for(i=1;i<=n;i++)
				{
					dp[s][i]=min(dp[s][i],dp[t][i]+dp[s^t][i]);
				}
			}
			dijkstra(s);
		}
		x=key_node.back();
		for(i=k;i<=n;i++) ans[x][i]=dp[(1<<k)-1][i];
	}
	void solve(int k)
	{
		int i;
		memset(ans,0x3f,sizeof ans);
		vector<int> id;
		for(i=1;i<=k;i++) id.push_back(i);
		for(i=k+1;i<=n;i++)
		{
			id.push_back(i);
			work(id);
			id.pop_back();
		}
	}
	#undef type
}stn;
/*
minimum spanning tree including all k key_node
O(n*3^k + m*log(m)*2^k)

stn.init(n);
stn.add_edge(a,b,w);
stn.work(key_node);
*/
int main()
{
	int n,k,i,j,q,x,y;
	scanf("%d%d",&n,&k);
	stn.init(n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&stn.mp[i][j]);
		}
	}
	stn.solve(k);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",stn.ans[x][y]);
	}
	return 0;
}
