#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
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
}dsu;
int in[MAX];
int main()
{
	int n,m,i,ok,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) in[i]=0;
	dsu.init(n);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		in[a]++;
		in[b]++;
		dsu.merge(a,b);
	}
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(in[i]!=2) ok=0;
	}
	if(dsu.sz[dsu.find(1)]!=n) ok=0;
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
