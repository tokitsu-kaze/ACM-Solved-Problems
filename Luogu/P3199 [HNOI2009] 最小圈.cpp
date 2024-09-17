#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct SPFA
{
	#define type long double
	const type inf=1e18;
	static const int N=3005;
	vector<pair<int,type> > mp[N];
	type dis[N];
	int n,vis[N],cnt[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	bool work(int s,type mid)
	{
		if(vis[s]) return true;
		int i,x,to;
		type w;
		queue<int> q;
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
				w=it.second-mid;
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
int ck(int n,long double x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		spfa.dis[i]=spfa.inf;
		spfa.vis[i]=spfa.cnt[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		if(!spfa.work(i,x)) return 1;
	}
	return 0;
}
int main()
{
	int n,m,i,a,b;
	long double c,l,r,mid;
	scanf("%d%d",&n,&m);
	spfa.init(n);
	while(m--)
	{
		scanf("%d%d%Lf",&a,&b,&c);
		spfa.add_edge(a,b,c);
	}
	l=-1e7;
	r=1e7;
	for(i=0;i<70;i++)
	{
		mid=(l+r)/2;
		if(ck(n,mid)) r=mid;
		else l=mid;
	}
	printf("%.8Lf\n",r);
	return 0;
}
