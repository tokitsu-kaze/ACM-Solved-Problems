#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=500+10;
struct SPFA
{
	#define type int
	static const int inf=INF;
	static const int N=MAX;
	vector<pair<int,type> > mp[N];
	type dis[N];
	int n,vis[N],cnt[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	bool work(int s)
	{
		int i,x,to;
		type w;
		queue<int> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=cnt[i]=0;
		}
		dis[s]=0;
		vis[s]=1;
		q.push(s);
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			vis[x]=0;
			for(auto &it:mp[x])
			{
				to=it.first;
				w=it.second;
				if(dis[to]>dis[x]+w)
				{
					dis[to]=dis[x]+w;
					cnt[to]=cnt[x]+1;
					if(cnt[to]>n)
					{
						// cnt is edge counts of current short path
						// if cnt >= (sum of node), the graph exists negative ring
						return false;
					}
					if(!vis[to])
					{
						q.push(to);
						vis[to]=1;
					}
				}
			}
		}
		return true;
	}
	#undef type
}spfa;
int main()
{
	int t,n,m,k,i,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		spfa.init(n+1);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			spfa.add_edge(a,b,c);
			spfa.add_edge(b,a,c);
		}
		while(k--)
		{
			scanf("%d%d%d",&a,&b,&c);
			spfa.add_edge(a,b,-c);
		}
		for(i=1;i<=n;i++) spfa.add_edge(n+1,i,0);
		if(spfa.work(n+1)) puts("NO");
		else puts("YES");
	}
	return 0;
}
