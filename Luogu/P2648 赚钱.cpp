#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct SPFA
{
	#define type int
	static const type inf=INF;
	static const int N=233;
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
	int d,p,c,f,s,i,a,b,w,ans;
	scanf("%d%d%d%d",&d,&p,&c,&f);
	s=c+1;
	spfa.init(s);
	for(i=1;i<=p;i++)
	{
		scanf("%d%d",&a,&b);
		spfa.add_edge(a,b,-d);
	}
	for(i=1;i<=f;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		spfa.add_edge(a,b,w-d);
	}
	for(i=1;i<=c;i++) spfa.add_edge(s,i,-d);
	if(!spfa.work(s))
	{
		puts("orz");
		return 0;
	}
	ans=0;
	for(i=1;i<=c;i++) ans=max(ans,-spfa.dis[i]);
	printf("%d\n",ans);
	return 0;
}

