////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-01 15:10:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2022
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1448KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m,n,a[101][101],i,j,s,x,y;
	while(~scanf("%d%d",&m,&n))
	{
		s=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				if(abs(a[i][j])>abs(s))
				{
					s=a[i][j];
					x=i+1;
					y=j+1;
				}
			}
		}
		printf("%d %d %d\n",x,y,s);
	}
	return 0;
}