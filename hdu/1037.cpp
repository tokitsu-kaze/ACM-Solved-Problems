////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-21 19:15:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int i,a,flag=0;
	for(i=0;i<3;i++)
	{
		scanf("%d",&a);
		if(a<168)
		{
			printf("CRASH %d\n",a);
			flag=1;
			break;
		}
	}
	if(flag==0) printf("NO CRASH\n");
    return 0;
}