////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-17 22:11:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2149
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>  
int main()  
{  
    int n,m;  
    while(~scanf("%d%d",&n,&m))  
    {  
        if(n%(m+1)==0) printf("none\n");
        else
        {
			if(n<=m)
			{
				for(;n<=m;n++)
				{
					printf("%d",n);
					if(n!=m) printf(" ");
					else printf("\n");
				}
			}
			else printf("%d\n",n%(m+1));
		}
    }  
    return 0;
} 