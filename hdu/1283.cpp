////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-07 10:10:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int a,b,l,i,x,y,z;
    char c[201];
    while(~scanf("%d%d",&a,&b))
    {
		x=0;
		y=0;
		z=0;
        scanf("%s",c);
        l=strlen(c);
        for(i=0;i<l;i++)
        {
			switch(c[i])
			{
				case 'A':x=a;break;
				case 'B':y=b;break;
				case 'C':a=z;break;
				case 'D':b=z;break;
				case 'E':z=x+y;break;
				case 'F':z=x-y;break;
			}
		}
		printf("%d,%d\n",a,b);
    }
    return 0;
}