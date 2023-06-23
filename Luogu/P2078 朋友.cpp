#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+10;
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
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			sz[rb]+=sz[ra];
			return 1;
		}
		return 0;
	}
}da,db;
int main()
{
	int n,m,p,q,i,a,b,ra,rb;
	scanf("%d%d%d%d",&n,&m,&p,&q);
	da.init(n);
	db.init(m);
	while(p--)
	{
		scanf("%d%d",&a,&b);
		da.merge(a,b);
	}
	while(q--)
	{
		scanf("%d%d",&a,&b);
		a=-a;
		b=-b;
		db.merge(a,b);
	}
	ra=da.sz[da.find(1)];
	rb=db.sz[db.find(1)];
	printf("%d\n",min(ra,rb));
	return 0;
}
