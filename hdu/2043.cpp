////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-10 22:57:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2043
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,i,j,k,l,r,t;
    char a[51];
    while(~scanf("%d",&n))
    {
		getchar();
		for(r=0;r<n;r++)
		{
			i=0;
			j=0;
			k=0;
			l=0;
			gets(a);
			x=strlen(a);
			for(t=0;t<x;t++)
			{
				if(a[t]>='A'&&a[t]<='Z') i=1;
				else if(a[t]>='a'&&a[t]<='z') j=1;
				else if(a[t]>='0'&&a[t]<='9') k=1;
				else l=1;
			}
			if(i+j+k+l>=3&&(x>=8&&x<=16)) printf("YES\n");
			else printf("NO\n");
		}
    }
    return 0;
}