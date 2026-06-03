#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
struct Dijkstra
{
	#define type int
	const type inf=INF;
	struct node
	{
		int id;
		type v;
		friend bool operator < (node a,node b){return a.v>b.v;}
	};
	struct edge{int to;type w;};
	static const int N=MAX;
	vector<edge> mp[N];
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
				to=it.to;
				w=it.w;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					q.push({to,dis[to]});
				}
			}
		}
	}
	#undef type
}dij;
vector<int> pos[55];
char s[55][55];
int a[MAX];
int main()
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++) pos[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
	}
	for(i=1;i<=k;i++) scanf("%s",s[i]+1);
	dij.init(n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(s[a[i]][j]=='0') continue;
			auto pre=lower_bound(pos[j].begin(),pos[j].end(),i);
			if(pre!=pos[j].begin())
			{
				pre--;
				dij.add_edge(i,*pre,i-*pre);
			}
			auto nex=upper_bound(pos[j].begin(),pos[j].end(),i);
			if(nex!=pos[j].end()) dij.add_edge(i,*nex,*nex-i);
		}
		if(s[a[i]][a[n]]=='1') dij.add_edge(i,n,n-i);
	}
	dij.work(1);
	if(dij.dis[n]==dij.inf) puts("-1");
	else printf("%d\n",dij.dis[n]);
	return 0;
}
/*
a<b<c
a->b a->c b->c
a->c = a->b + b->c
把边权拆贡献，连相邻的即可。

颜色 x 连到 颜色 y，但 颜色 y 内部不能互相连。
假设此时有 x y1 y2，y2 的位置为 颜色 n，
那么只连 (x,y1) 是走不到 y2 的。 

再考虑 n 的颜色不为 y 的情况，要证明此时 (x,y2) 是无用边。
颜色不为 y 也就是说，从 x 不能直接走到 n，要走中转点 
考虑中转点的位置 x y1 y2 z，那我走 x -> y1 -> z 不劣于 x -> y2 -> z
感觉讨论一下中转点位置能证
*/
