#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e4+10;
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
int to[MAX];
int main()
{
	int n,m,i,a,b,ans;
	char op[3];
	scanf("%d",&n);
	dsu.init(n);
	for(i=1;i<=n;i++) to[i]=0;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%d%d",op,&a,&b);
		if(op[0]=='F') dsu.merge(a,b);
		else
		{
			if(to[a]) dsu.merge(to[a],b);
			if(to[b]) dsu.merge(a,to[b]);
			to[a]=b;
			to[b]=a;
		}
	}
	ans=0;
	for(i=1;i<=n;i++) ans+=(dsu.find(i)==i);
	printf("%d\n",ans);
	return 0;
}
