////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-20 20:11:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2566
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1476KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int t,n,m,c1[101][101],c2[101][101],i,j,k,h;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
			scanf("%d%d",&n,&m);
			memset(c1,0,sizeof(c1));
			memset(c2,0,sizeof(c2));
			for(i=0;i<=n;i++)
			{
				c1[i][i]=1;
			}
			for(i=2;i<=5;i+=3)
			{
				for(j=0;j<=m;j++)
				{
					for(k=0;k*i+j<=m;k++)
					{
						for(h=0;k+h<=n;h++)
						{
							c2[k*i+j][k+h]+=c1[j][h];
						}
					}
				}
				for(j=0;j<=m;j++)
				{
					for(k=0;k<=m;k++)
					{
						c1[j][k]=c2[j][k];
						c2[j][k]=0;
					}
				}
			}
			printf("%d\n",c1[m][n]);
		}
    }
    return 0;
}