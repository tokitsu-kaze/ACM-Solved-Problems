#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4e5+10;
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
int main()
{
	int n,m,i,a,b,ok;
	scanf("%d%d",&n,&m);
	dsu.init(2*n);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		dsu.merge(a,b+n);
		dsu.merge(a+n,b);
	}
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(dsu.find(i)!=dsu.find(i+n)) ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
