////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 18:09:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2099
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int a,b,c,flag;
    while(~scanf("%d%d",&a,&b))
    {
		if(a==0&&b==0) break;
		flag=0;
		for(c=0;c<=99;c++)
		{
			if((a*100+c)%b==0)
			{
				if(flag==1) printf(" ");
				printf("%02d",c);
				flag=1;
			}
		}
		printf("\n");
	}
    return 0;
}
