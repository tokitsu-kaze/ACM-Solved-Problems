////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-02 09:19:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2027
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	struct
	{
		int a,e,i,o,u;
	}count[10000]={0,0,0,0,0};
	int n,i,j,x;
	char y[101];
	while(~scanf("%d",&n))
	{
		getchar();
		for(i=0;i<n;i++)
		{
			gets(y);
			x=strlen(y);
			for(j=0;j<x;j++)
			{
				switch(y[j])
				{
					case 'a':count[i].a++;break;
					case 'e':count[i].e++;break;
					case 'i':count[i].i++;break;
					case 'o':count[i].o++;break;
					case 'u':count[i].u++;break;
				}
			}
			printf("a:%d\n",count[i].a);
			printf("e:%d\n",count[i].e);
			printf("i:%d\n",count[i].i);
			printf("o:%d\n",count[i].o);
			printf("u:%d\n",count[i].u);
			if(i!=n-1) printf("\n");
		}
	}
	return 0;
}