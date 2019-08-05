////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-10 20:06:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3079
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int n,x,i,k,s,j;
    char a[100],b[1001];
    while(~scanf("%d",&n))
    {
		getchar();
		k=0;
		for(j=0;j<n;j++)
		{
			gets(a);
			x=strlen(a);
			for(i=0;i<=x;i++)
			{
				if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
				{
					a[i]=toupper(a[i]);
				}
				else if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U');
				else a[i]=tolower(a[i]);
			}
			printf("%s\n",a);
		}	
	}
    return 0;
}