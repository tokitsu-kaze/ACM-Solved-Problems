////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-28 21:46:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2015
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,i,j,a,s;
	while(~scanf("%d%d",&n,&m))
	{
		a=0;
		j=0;
		s=0;
		i=0;
		while(i<n)
		{
			a=a+2;
			j++;
			s=s+a;
			if(j==m)
			{
				if(a==2*m)
				printf("%d",s/m);
				else printf(" %d",s/m);
				j=0;
				s=0;
			}
			i++;
		}
		if(j!=0) printf(" %d\n",s/j);
		else printf("\n");
	}
	return 0;
}