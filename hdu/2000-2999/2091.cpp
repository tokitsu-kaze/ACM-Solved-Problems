////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 16:23:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2091
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int b,i,j,s,k,h,x=0;
    char a;
    while(~scanf(" %c",&a))
    {
		if(a=='@') break;
		if(x!=0) printf("\n");
		scanf("%d",&b);
		s=0;
		x=1;
		for(i=1;i<b;i++)
		{
			j=b;
			for(j=j-s;j>0;j--)
			{
				if(j!=1) printf(" ");
				else printf("%c",a);
			}
			if(i>=2)
			{
				for(h=2*s;h>0;h--)
				{
					if(h!=1) printf(" ");
					else printf("%c",a);
				}
			}
			printf("\n");
			s++;
		}
		for(i=2*b-1;i>0;i--)
		{
			printf("%c",a);
		}
		printf("\n");
	}
    return 0;
}