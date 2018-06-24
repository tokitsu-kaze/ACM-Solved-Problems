////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-21 19:34:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1396KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int i,len;
    char a[100],c[10001];
    while(gets(a))
    {
		if(strcmp(a,"ENDOFINPUT")==0) break;
		gets(c);
		len=strlen(c);
		for(i=0;i<len;i++)
		{
			if(c[i]>='A'&&c[i]<='E') c[i]=c[i]+21;
			else if(c[i]>='F'&&c[i]<='Z') c[i]=c[i]-5;
		}
		printf("%s\n",c);
		gets(a);
	}
    return 0;
}