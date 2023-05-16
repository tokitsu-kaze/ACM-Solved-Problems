////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 12:10:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1406
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b,c,i,j,k,s;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			s=0;
			scanf("%d%d",&a,&b);
			if(a>b)
			{
				c=a;
				a=b;
				b=c;
			}
			for(;a<=b;a++)
			{
				k=0;
				for(j=1;j<a;j++)
				{
					if(a%j==0) k=k+j;
				}
				if(k==a) s++;
			}
			printf("%d\n",s);
		}
	}
	return 0;
}