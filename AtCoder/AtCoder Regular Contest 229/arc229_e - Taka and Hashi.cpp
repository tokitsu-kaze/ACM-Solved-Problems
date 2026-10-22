#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Disjoint_Set_Union
{
	vector<int> pre,sz;
	void init(int n)
	{
		int i;
		pre.resize(n+2);
		sz.resize(n+2);
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu2,dsu3;
vector<int> mp[MAX];
int vis[MAX];
map<pair<int,int>,vector<int>> achieve_id;
void bfs()
{
	int t;
	queue<int> q;
	q.push(1);
	vis[1]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(auto &to:mp[t])
		{
			if(!vis[to])
			{
				vis[to]=1;
				q.push(to);
			}
		}
		for(auto &to:achieve_id[{dsu2.find(t),dsu3.find(t)}])
		{
			if(!vis[to])
			{
				vis[to]=1;
				q.push(to);
			}
		}
	}
}
int main()
{
	int T,n,m,i,a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			vis[i]=0;
		}
		dsu2.init(n);
		dsu3.init(n);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(c==2) dsu2.merge(a,b);
			else if(c==3) dsu3.merge(a,b);
			else
			{
				mp[a].push_back(b);
				mp[b].push_back(a);
			}
		}
		achieve_id.clear();
		for(i=1;i<=n;i++) achieve_id[{dsu2.find(i),dsu3.find(i)}].push_back(i);
		bfs();
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			if(vis[i]) res.push_back(i);
		}
		printf("%d\n",(int)res.size());
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}
/*
好像直接bfs就是对的？
这样似乎无法保证是从同一个点分裂出去的。

能够在 a 分裂在 b 合并，说明 a 只走 2 边能到 b；a 只走 3 边，也能到 b。
用两个并查集分别把 2 边和 3 边并起来。
将结果捆绑起来 (dsu2(i),dsu3(i)) 看成一个集合。
现在开始 bfs。如果只走 1 边能够到达这个集合中任意一个点，
说明能到达集合中所有点，于是将这些点全都放入队列。
*/
