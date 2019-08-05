////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-28 20:54:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int x,y,f,i,j;
	while(~scanf("%d%d",&x,&y))
	{
		if(x==0&&y==0) break;
		j=0;
		while(x<=y)
		{
			f=x*x+x+41;
			for(i=2;i<f;i++)
			{
				if(f%i==0) j++;
			}
			x++;
		}
		if(j==y-x+1) printf("OK\n");
		else printf("Sorry\n");
	}
	return 0;
}