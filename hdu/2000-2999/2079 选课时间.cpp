////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-20 08:59:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2079
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int c1[1001],c2[1001],i,j,k,a[101],b[101],t,n,m,s;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
			scanf("%d%d",&n,&m);
			for(i=1;i<=m;i++)
			{
				scanf("%d%d",&a[i],&b[i]);
			}
			memset(c1,0,sizeof(c1));
			memset(c2,0,sizeof(c2));
			for(i=0;i<=b[1];i++)
			{
				c1[i*a[1]]=1;
			}
			for(i=2;i<=m;i++)
			{
				for(j=0;j<=n;j++)
				{
					for(k=0,s=0;s<=b[i]&&k+j<=n;k+=a[i],s++)
					{
						c2[j+k]+=c1[j];
					}
				}
				for(j=0;j<=n;j++)
				{
					c1[j]=c2[j];
					c2[j]=0;
				}
			}
			printf("%d\n",c1[n]);
		} 
    }
    return 0;
}