#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX],g[MAX];
char s[MAX];
int c[MAX],in[MAX];
void dfs(int x,int fa)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		if(c[to])
		{
			g[to].push_back(x);
			in[x]++;
		}
		else
		{
			g[x].push_back(to);
			in[to]++;
		}
		c[x]^=c[to];
	}
}
vector<int> topsort(int n,vector<int> mp[],int *in)
{
	int i,x;
	priority_queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(-i);
	}
	vector<int> toplist;
	while(!q.empty())
	{
		x=-q.top();
		q.pop();
		toplist.push_back(x);
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(-to);
		}
	}
	return toplist;
}
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		g[i].clear();
		in[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='W') c[i]=1;
		else c[i]=0;
	}
	dfs(1,0);
	auto res=topsort(n,g,in);
	if(c[1]==0 || res.size()!=n) return 0*puts("-1");
	for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i+1==n]);
	return 0;
}
/*
如果从中间删，会把树搞出多个连通块，不好考虑。所以从叶子开始考虑。
如果叶子是白，那么一定先操作叶子；
如果叶子是黑，那么只能先操作它父亲。
考虑根据操作顺序进行连边，a->b 表示先操作 a 再操作 b。
那么只要：dfs一遍模拟求出叶子颜色，连边，跑拓扑排序即可。

要注意的是，当叶子是黑的时，不管父亲是什么颜色，一定要先操作父亲。
因为父亲可能会先通过操作其他叶子转成白，并且由于连边的意义只是操作的先后顺序。
所以我们不需要管父亲的颜色，反正知道要先操作父亲就对了。
*/
