#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
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
}dsu[11];
int main()
{
	int n,q,i,j,a,b,c,ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=10;i++) dsu[i].init(n);
	for(i=2;i<=n;i++) dsu[10].merge(1,i);
	ans=10*(n-1);
	for(i=1;i<=n-1+q;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(j=c;j<=10;j++)
		{
			if(dsu[j].find(a)==dsu[j].find(b)) continue;
			ans--;
			dsu[j].merge(a,b);
		}
		if(i>n-1) printf("%d\n",ans);
	}
	return 0;
}
