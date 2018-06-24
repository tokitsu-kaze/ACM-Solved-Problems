////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-01 14:32:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,i,j,s;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			while(a-100>=0)
			{
				s++;
				a=a-100;
			}
			while(a-50>=0)
			{
				s++;
				a=a-50;
			}
			while(a-10>=0)
			{
				s++;
				a=a-10;
			}
			while(a-5>=0)
			{
				s++;
				a=a-5;
			}
			while(a-2>=0)
			{
				s++;
				a=a-2;
			}
			while(a!=0)
			{
				s++;
				a--;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}