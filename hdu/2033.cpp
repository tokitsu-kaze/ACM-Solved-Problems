////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 10:06:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b,c,d,e,f,i,j,x,y,z;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
			x=a+d;
			y=b+e;
			z=c+f;
			if(z>=60)
			{
				y=y+z/60;
				z=z-z/60*60;
			}
			if(y>=60)
			{
				x=x+y/60;
				y=y-y/60*60;
			}
			printf("%d %d %d\n",x,y,z);
		}
	}
	return 0;
}