#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int totid,id[MAX],col[MAX],kind[MAX],tag[MAX];
int a[MAX],b[MAX],st[MAX],top;
map<pair<int,int>,int> e;
void dfs(int x,int fa,int c)
{
	id[x]=totid;
	col[x]=c;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		if(id[to])
		{
			if(col[to]!=(c^1)) kind[totid]=0;
			continue;
		}
		dfs(to,x,!c);
	}
}
int ckmatch(int x,int y)
{
	if(id[x]!=id[y]) return 0;
	if(kind[id[x]]==0) return 1;
	
	// kind=1
	if(col[x]^col[y]) return 1;
	return 0;
}
vector<int> work(int l,int r,int *x)
{
	int i;
	top=0;
	for(i=l;i<=r;i++)
	{
		if(top && ckmatch(st[top-1],x[i])) top--;
		else st[top++]=x[i];
	}
	vector<int> res;
	for(i=0;i<top;i++) res.push_back(st[i]);
	return res;
}
int ckseg(int l,int r,int *x,int *y)
{
	int i,okx,oky;
	okx=oky=0;
	for(i=l;i<r;i++)
	{
		if(e.count({x[i],x[i+1]})) okx=1;
		if(e.count({y[i],y[i+1]})) oky=1;
	}
	if(!okx || !oky)
	{
		for(i=l;i<=r;i++)
		{
			if(x[i]!=y[i]) return 0;
		}
		return 1;
	}
	auto rx=work(l,r,x);
	auto ry=work(l,r,y);
	if(rx.size()!=ry.size()) return 0;
	for(i=0;i<rx.size();i++)
	{
		if(id[rx[i]]!=id[ry[i]]) return 0;
		if(col[rx[i]]!=col[ry[i]]) return 0;
	}
	return 1;
}
int main()
{
	int n,m,k,T,i,j,x,y,ok,pre;
	scanf("%d%d%d",&m,&k,&T);
	for(i=1;i<=k;i++)
	{
		mp[i].clear();
		id[i]=col[i]=kind[i]=tag[i]=0;
	}
	e.clear();
	while(m--)
	{
		scanf("%d%d",&x,&y);
		e[{x,y}]=e[{y,x}]=1;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	totid=0;
	for(i=1;i<=k;i++)
	{
		if(mp[i].size()==0) tag[i]=1;
		if(id[i]) continue;
		totid++;
		kind[totid]=1;
		dfs(i,0,0);
	}
	for(i=1;i<=k;i++)
	{
		if(!kind[id[i]]) col[i]=0;
	}
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ok=1;
		pre=1;
		a[n+1]=b[n+1]=0;
		tag[0]=1;
		for(i=1;i<=n+1;i++)
		{
			if(tag[a[i]] || tag[b[i]])
			{
				if(a[i]!=b[i]) ok=0;
				if(!ckseg(pre,i-1,a,b)) ok=0;
				pre=i+1;
			}
			if(!ok) break;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
题意就是，任意 (a[i],a[i+1]) 边，可以替换为任意边，问能否将序列 a 变成序列 b。

先处理孤立点，把序列分成若干子段。子段内如果没有任何 (a[i],a[i+1]) 边，说明这个子段完全动不了。
然后考虑每个点都是自环的情况，发现边在序列中可以任意移动，变成了经典问题消消乐。

现在考虑一般情况，考虑将每个点替换成等价类。等价类分是否是二分图。
- 是二分图，同一个二分图内，染色后相邻边就是 (0,1)，替换永远是 (0,1) 或者 (1,0) ，不可能替换成相同颜色。
所以这个二分图内每个点颜色相同视为同一个等价类，等价类为 (id,颜色)。
匹配时类似括号匹配；
- 不是二分图，同一个连通块的点任意替换成其他点。
所以整个连通块的点视为同一个等价类，等价类为 (id)。
匹配时就是消消乐。

将序列 a 和 b 所有数转化成等价类，消完后对比一下即可。


2 3 1
1 2
2 3
2
1 3
3 1
ans=NO
*/
