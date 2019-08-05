////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-03 23:03:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2052
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:2380KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,m,i,j,h;
	char a[1000][1000],b[100];

	while(~scanf("%d%d",&n,&m))
	{
		memset(a,' ',sizeof(a));
		gets(b);
		if(strcmp(b,"EOF")==0) break;
		a[0][0]='+';
		a[0][n+1]='+';
		a[m+1][0]='+';
		a[m+1][n+1]='+';
		for(i=1;i<n+1;i++)
		{
			a[0][i]='-';
			a[m+1][i]='-';
		}
		for(i=1;i<m+1;i++)
		{
			a[i][0]='|';
			a[i][n+1]='|';
		}
		for(i=0;i<=m+1;i++)
		{
			for(j=0;j<=n+1;j++)
			{
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
	}
	return 0;
}