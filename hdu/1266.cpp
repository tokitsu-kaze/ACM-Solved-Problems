////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 22:33:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1266
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	__int64 n,len,i,flag,x,b;
	char a[100];
    while(~scanf("%I64d",&n))
    {
		while(n--)
		{
			scanf("%I64d",&b);
			sprintf(a,"%I64d",b);
			len=strlen(a);
			flag=x=0;
			if(a[0]=='-') printf("%c",a[0]);
			for(i=len-1;i>0;i--)
			{
				if(flag==1) printf("%c",a[i]);
				else if(a[i]!='0')
				{
					printf("%c",a[i]);
					flag=1;
					x=i;
				}
			}
			if(a[0]!='-')
			{
				printf("%c",a[0]);
				//x--;
			}
			for(i=len-1;i>x;i--)
			{
				printf("0");
			}
			printf("\n");
		}
    }
    return 0;
}