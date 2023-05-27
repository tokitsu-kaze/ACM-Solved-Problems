////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 22:40:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1718
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int a[1000],b,i,k;
    while(~scanf("%d",&a[0]))
    {
		k=0;
		for(i=1;;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0&&a[i-1]==0) break;
		}
		for(i=1;;i=i+2)
		{
			if(a[0]==a[i]) break;
		}
		b=a[i+1];
		for(i=2;;i=i+2)
		{
			if(a[i]>b) k++;
			if(a[i]==0) break;
		}
		printf("%d\n",k+1);
	}
	return 0;
}