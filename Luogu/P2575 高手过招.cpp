#include <bits/stdc++.h>
using namespace std;
const int MAX=(1<<20)+5;
int sg[MAX];
int dfs(int x)
{
	if(sg[x]!=-1) return sg[x];
	int i,j,nex;
	set<int> s;
	nex=20;
	for(i=19;~i;i--)
	{
		if(!((x>>i)&1)) nex=i;
		else
		{
			if(nex<=19)
			{
				dfs(x^(1<<i)^(1<<nex));
				s.insert(sg[x^(1<<i)^(1<<nex)]);
			}
		}
	}
	for(i=0;;i++)
	{
		if(!s.count(i))
		{
			j=i;
			break;
		}
	}
	return sg[x]=j;
}
int main()
{
	int t,n,m,i,x,s,res;
	memset(sg,-1,sizeof sg);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res=0;
		while(n--)
		{
			scanf("%d",&m);
			s=0;
			for(i=0;i<m;i++)
			{
				scanf("%d",&x);
				s|=(1<<(x-1));
			}
			res^=dfs(s);
		}
		if(res) puts("YES");
		else puts("NO");
	}
	return 0;
}
