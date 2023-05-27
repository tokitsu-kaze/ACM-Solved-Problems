////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 12:25:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2055
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,b;
	char a;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%c%d",&a,&b);
			if(a>='A'&&a<='Z') printf("%d\n",a-64+b);
			else if(a>='a'&&a<='z') printf("%d\n",96-a+b);
		}
	}
	return 0;
}