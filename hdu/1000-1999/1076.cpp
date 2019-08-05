////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 18:29:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1076
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,y,n,i; 
    while(~scanf("%d",&t))
    {
		while(t--)
		{
			scanf("%d%d",&y,&n);
			if(y%4!=0) y=y-y%4+4;
			for(i=y;n>0;i+=4)
			{
				if((i%4==0&&i%100!=0)||i%400==0) n--;
			}
			printf("%d\n",i-4);
		}
    }
    return 0;
}