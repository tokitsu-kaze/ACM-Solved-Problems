////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 20:55:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1303
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a[1001],i,j,k,count;
    while(~scanf("%d",&a[0]))
    {
		if(a[0]==-1) break;
		for(i=1;;)
		{
			scanf("%d",&a[i++]);
			if(a[i-1]==0) break;
		}
		for(j=0,count=0;j<i-1;j++)
		{
			for(k=0;k<i-1;k++)
			{
				if(a[j]*2==a[k]) count++;
			}
		}
		printf("%d\n",count);
    }
    return 0;
}