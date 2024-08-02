#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace test
{
	int sg[105][105][105];
	int dfs(int a,int b,int c)
	{
		if(sg[a][b][c]!=-1) return sg[a][b][c];
		int i,j,flag[1111];
		memset(flag,0,sizeof flag);
		for(i=1;i<a;i++)
		{
			flag[dfs(a-i,i,c)]=1;
			flag[dfs(a-i,b,i)]=1;
		}
		for(i=1;i<b;i++)
		{
			flag[dfs(i,b-i,c)]=1;
			flag[dfs(a,b-i,i)]=1;
		}
		for(i=1;i<c;i++)
		{
			flag[dfs(a,i,c-i)]=1;
			flag[dfs(i,b,c-i)]=1;
		}
		for(i=0;;i++)
		{
			if(!flag[i])
			{
				j=i;
				break;
			}
		}
		return sg[a][b][c]=j;
	}
	void work()
	{
		memset(sg,-1,sizeof sg);
		sg[1][1][1]=0;
		int a,b,c;
		for(a=1;a<=10;a++)
		{
			for(b=1;b<=10;b++)
			{
				for(c=1;c<=10;c++)
				{
					if(!(a%2==b%2 && a%2==c%2)) assert(dfs(a,b,c));
					else printf("%d %d %d %s\n",a,b,c,dfs(a,b,c)?"YES":"NO");
				}
			}
		}
	}
}
int main()
{
//	test::work();
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a%2==b%2 && a%2==c%2)
		{
			if(a%2==0)
			{
				while(a%2==0 && b%2==0 && c%2==0)
				{
					a/=2;
					b/=2;
					c/=2;
				}
				if(a%2 && a%2==b%2 && a%2==c%2) puts("NO");
				else puts("YES");
			}
			else puts("NO");
		}
		else puts("YES");
	}
	return 0;
}
