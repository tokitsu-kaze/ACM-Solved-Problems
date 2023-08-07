////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 13:56:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1428KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int b,c,n,i;
	char a;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%c%d%d",&a,&b,&c);
			if(b%c==0)
			{
			switch(a)
				{
					case '+':printf("%d\n",b+c); break;
					case '-':printf("%d\n",b-c); break;
					case '*':printf("%d\n",b*c); break;
					case '/':printf("%d\n",b/c); break;
				}
			}
			else
			{
			switch(a)
				{
					case '+':printf("%d\n",b+c); break;
					case '-':printf("%d\n",b-c); break;
					case '*':printf("%d\n",b*c); break;
					case '/':printf("%.2f\n",1.0*b/c); break;
				}
			}
		}
	}
	return 0;
}
