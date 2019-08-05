////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-24 18:05:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1279
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1444KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,i,flag,count,b[10001];
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d",&a);
			for(i=a,flag=0,count=0;;)
			{
				if(i%2!=0)
				{
					b[++count]=i;
					i=i*3+1;
					flag=1;
				}
				else i/=2;
				if(i==1) break;
			}
			if(flag==0) printf("No number can be output !");
			else
			{
				for(i=1;i<=count;i++)
				{
					printf("%d",b[i]);
					if(i!=count) printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}