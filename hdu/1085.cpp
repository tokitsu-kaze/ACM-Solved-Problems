////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-19 19:09:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1085
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1476KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    int c1[10001],c2[10001],i,j,k,a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        if(a==0&&b==0&&c==0) break;
        for(i=0;i<=a+2*b+5*c;i++)
        {
			c1[i]=1;
			c2[i]=0;
		}
		for(i=0;i<=a;i++)
		{
			for(j=0;j<=2*b;j+=2)
			{
				c2[i+j]+=c1[i];
			}
		}
		for(j=0;j<=2*b;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
		for(i=0;i<=a+2*b;i++)
		{
			for(j=0;j<=5*c;j+=5)
			{
				c2[i+j]+=c1[i];
			}
		}
		for(j=0;j<=5*c;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
		for(i=0;i<=a+2*b+5*c;i++)
		{
			if(c1[i]==0) break;
		}
		printf("%d\n",i);
    }
    return 0;
}