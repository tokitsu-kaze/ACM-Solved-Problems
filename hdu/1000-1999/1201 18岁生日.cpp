////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 19:38:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1201
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,y,m,d,sum,i; 
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%d-%d-%d",&y,&m,&d);
			if(m==2&&d==29)
			{
				printf("-1\n");
				continue;
			}
			sum=0;
			if(m<=2&&((y%4==0&&y%100!=0)||y%400==0)) sum++;
			if(m>=3&&(((y+18)%4==0&&(y+18)%100!=0)||(y+18)%400==0)) sum++;
			for(i=1;i<=17;i++)
			{
				if((((y+i)%4==0&&(y+i)%100!=0)||(y+i)%400==0)) sum++;
			}
			printf("%d\n",sum+18*365);
		}
    }
    return 0;
}