////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-02 09:33:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2017
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j,x[1000],y;
	char a[1000];
	while(~scanf("%d",&n))
	{
		getchar();
		for(i=0;i<n;i++)
		{
			x[i]=0;
			gets(a);
			y=strlen(a);
			for(j=0;j<y;j++)
			{
				switch(a[j])
				{
					case '0':x[i]++;break;
					case '1':x[i]++;break;
					case '2':x[i]++;break;
					case '3':x[i]++;break;
					case '4':x[i]++;break;
					case '5':x[i]++;break;
					case '6':x[i]++;break;
					case '7':x[i]++;break;
					case '8':x[i]++;break;
					case '9':x[i]++;break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d\n",x[i]);
		}
	}
	return 0;
}