#include <bits/stdc++.h>
using namespace std;
const int MAX=1000+10;
struct Disjoint_Set_Union
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
int main()
{
	int n,m,a,b,cnt,i;
	while(~scanf("%d",&n)&&n>0)
	{
		scanf("%d",&m);
		dsu.init(n);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			dsu.merge(a,b);
		}
		cnt=0;
		for(i=1;i<=n;i++) cnt+=(dsu.find(i)==i);
		printf("%d\n",cnt-1);
	}
	return 0;
}
