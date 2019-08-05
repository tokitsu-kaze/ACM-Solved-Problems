////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 19:05:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2161
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,i=1,j;
	while(~scanf("%d",&a))
	{
		if(a<=0) break;
		if(a==1||a==2)
		{
			printf("%d: no\n",i);
			i++;
		}
		else
		{
			for(j=2;j<a;j++)
			{
				if(a%j==0) break;
			}
			if(j==a)
			{
				printf("%d: yes\n",i);
				i++;
			}
			else
			{
				printf("%d: no\n",i);
				i++;
			}
		}
	}
	return 0;
}