////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-03 15:04:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2024
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j,x,h;
	char a[51];
	while(~scanf("%d",&n))
	{
		getchar();
		for(i=0;i<n;i++)
		{
			h=0;
			gets(a);
			if((a[0]>='A'&&a[0]<='Z')||(a[0]>='a'&&a[0]<='z')||a[0]=='_')
			{
				x=strlen(a);
				for(j=1;j<=x;j++)
				{
					if((a[j]>='A'&&a[j]<='Z')||(a[j]>='a'&&a[j]<='z')||(a[j]>='0'&&a[j]<='9')||a[j]=='_')
					h++;
				}
				if(h==x-1) printf("yes\n");
				else printf("no\n");
			}
			else printf("no\n");
		}
	}
	return 0;
}