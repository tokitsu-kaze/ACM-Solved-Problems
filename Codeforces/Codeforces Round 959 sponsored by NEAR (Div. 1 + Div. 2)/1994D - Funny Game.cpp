#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
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
int v[MAX],a[MAX],b[MAX],pre[MAX];
int main()
{
	int T,n,i,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		dsu.init(n);
		for(x=n-1;x;x--)
		{
			memset(pre,0,sizeof pre);
			for(i=1;i<=n;i++)
			{
				if(pre[v[i]%x])
				{
					if(dsu.merge(pre[v[i]%x],i))
					{
						a[x]=pre[v[i]%x];
						b[x]=i;
						break;
					}
				}
				pre[v[i]%x]=i;
			}
		}
		puts("YES");
		for(i=1;i<=n-1;i++) printf("%d %d\n",a[i],b[i]);
	}
	return 0;
}
/*
发现样例全yes，感觉从大到小枚举x，模拟一下就行。
原来是，鸽笼原理。
*/
