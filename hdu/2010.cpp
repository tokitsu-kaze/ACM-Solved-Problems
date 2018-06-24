////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-28 14:26:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2010
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1428KB
//////////////////System Comment End//////////////////
#include <stdio.h> 
#include <math.h>
int main()
{
	int m,n,a,b,c,x,i,j;
	while(~scanf("%d%d",&m,&n))
	{
		i=0;
		j=0;
		while(m<=n)
		{
			a=m/100;
			b=m/10%10;
			c=m%10; 
			x=pow(a,3)+pow(b,3)+pow(c,3);
			if(x==m)
			{
				if(j==1)
				{
					printf(" ");
					j=0;
				}
				printf("%d",m);
				i++;
				j++;
			}
			m++;
		}
		if(i==0) printf("no\n");
		else printf("\n");
	}
	return 0;
}