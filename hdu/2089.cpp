////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 14:13:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2089
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:5320KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int c[1000001];
int main()
{
    int a,b,i,j,k,s;
    char x[100];
    memset(c,0,sizeof(c));
    for(j=1;j<=1000001;j++)
    {
		memset(x,'0',sizeof(x));
        sprintf(x,"%d",j);
        for(i=0;i<strlen(x);i++)
       	{
        	if(x[i]=='4'||(x[i]=='6'&&x[i+1]=='2'))
            {
            	c[j]=1;
            }
        }
	}
    while(~scanf("%d%d",&a,&b))
    {
        s=0;
        if(a==0&&b==0) break;
        for(k=a;k<=b;k++)
        {
			if(c[k]==1) s++;
		}
        printf("%d\n",b-a-s+1);
    }
    return 0;
}