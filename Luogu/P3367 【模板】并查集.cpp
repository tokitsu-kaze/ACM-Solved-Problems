#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
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
	int n,m,op,x,y;
	scanf("%d%d",&n,&m);
	dsu.init(n);
	while(m--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) dsu.merge(x,y);
		else puts(dsu.find(x)==dsu.find(y)?"Y":"N");
	}
	return 0;
}
