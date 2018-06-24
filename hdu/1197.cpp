////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-11 13:32:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1197
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1384KB
//////////////////System Comment End//////////////////
#include <stdio.h>
void exchange(int a)
{
	int i,j=0,k=0,b,c;
	b=a;
	c=a;
	i=a/1000+a/100%10+a/10%10+a%10;
	while(b>0)
	{
		j=j+b%12;
		b=b/12;
	}
	while(c>0)
	{
		k=k+c%16;
		c=c/16;
	}
	if(i==j&&j==k) printf("%d\n",a);
}
int main()
{
	int i;
	for(i=2992;i<=9999;i++)
	{
		exchange(i);
	}
	return 0;
}