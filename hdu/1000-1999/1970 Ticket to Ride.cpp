#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct Minimum_Steiner_Tree
{
	#define type int
	const type inf=INF;
	static const int N=30+5;
	static const int K=8;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	vector<node> mp[N];
	type dp[(1<<K)+3][N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=1;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){ mp[x].push_back({y,v});}
	void dijkstra(int s)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
			if(dp[s][i]!=inf) q.push({i,dp[s][i]});
		}
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id]) continue;
			vis[t.id]=1;
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.v;
				if(dp[s][to]>dp[s][t.id]+w)
				{
					dp[s][to]=dp[s][t.id]+w;
					if(!vis[to]) q.push({to,dp[s][to]}); 
				}
			}
		}
	}
	type work(vector<int> key_node)
	{
		int s,t,i,k;
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
		res=inf;
		for(i=1;i<=n;i++) res=min(res,dp[(1<<k)-1][i]);
		return res;
	}
	#undef type
}stn;
/*
stn.init(n);
stn.add_edge(a,b,w);
stn.work(key_node);
*/
int ans[(1<<8)+5];
int main()
{
	int n,m,i,c,s,t,ok,tmp;
	char a[22],b[22];
	while(~scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0) break;
		stn.init(n);
		map<string,int> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%s",a);
			mp[a]=i;
		}
		while(m--)
		{
			scanf("%s%s%d",a,b,&c);
			stn.add_edge(mp[a],mp[b],c);
			stn.add_edge(mp[b],mp[a],c);
		}
		vector<int> key_node(8);
		for(i=0;i<8;i++)
		{
			scanf("%s",a);
			key_node[i]=mp[a];
		}
		stn.work(key_node);
		memset(ans,0x3f,sizeof ans);
		for(s=0;s<(1<<8);s++)
		{
			for(i=1;i<=n;i++)
			{
				ans[s]=min(ans[s],stn.dp[s][i]);
			}
		}
		for(s=0;s<(1<<8);s++)
		{
			ok=1;
			for(i=0;i<8;i+=2)
			{
				tmp=(1<<i)+(1<<(i+1));
				if((s&(tmp))>0&&(s&(tmp))!=tmp) ok=0;
			}
			if(!ok) continue;
			for(t=s&(s-1);t;t=s&(t-1))
			{
				ok=1;
				for(i=0;i<8;i+=2)
				{
					tmp=(1<<i)+(1<<(i+1));
					if((t&(tmp))>0&&(t&(tmp))!=tmp) ok=0;
				}
				if(!ok) continue;
				ans[s]=min(ans[s],ans[t]+ans[s^t]);
			}
		}
		printf("%d\n",ans[(1<<8)-1]);
	}
	return 0;
}
