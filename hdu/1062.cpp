////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-20 21:10:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1062
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1452KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int len,i,j,k,n,a[10001];
    char c[10001];
    while(~scanf("%d",&n))
    {
        getchar();
        while(n--)
        {
			gets(c);
			len=strlen(c);
			a[0]=0;
			for(i=0,j=1;i<=len;i++)
			{
				if(c[i]==' ') a[++j]=i+1;
			}
			a[++j]=len+1;
			for(i=1;i<=j;i++)
			{
				for(k=a[i]-2;k>=a[i-1];k--)
				{
					printf("%c",c[k]);
				}
				if(i!=j&&i!=1) printf(" ");
				else if(i==j) printf("\n");
			}
		}
    }
    return 0;
}