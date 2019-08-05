////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 13:49:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char a[100001],b[100001];
int main()
{
	int i,flag;
	memset(a,'0',sizeof(a));
	memset(b,'0',sizeof(b));
	while(~scanf("%s%s",a,b))
	{
		flag=0;
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]=='.') flag=1;
		}
		if(flag==0) a[i]='.';
		else a[i]='0';
		a[100000]='\0';
		flag=0;
		for(i=0;b[i]!='\0';i++)
		{
			if(b[i]=='.') flag=1;
		}
		if(flag==0) b[i]='.';
		else b[i]='0';
		b[100000]='\0';
		flag=0;
		if(strcmp(a,b)==0) printf("YES\n");
		else printf("NO\n");
		memset(a,'0',sizeof(a));
		memset(b,'0',sizeof(b));
	}
	return 0;
}