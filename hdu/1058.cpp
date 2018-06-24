////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-21 21:35:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1058
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1440KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int a[5850];
int main()
{
    int i,p2,p3,p5,p7,n;
    a[1]=1;
    p2=p3=p5=p7=1;
	for(i=1;a[i]<2000000000;)
	{
		a[++i]=min(min(2*a[p2],3*a[p3]),min(5*a[p5],7*a[p7]));
		if(a[i]==2*a[p2]) p2++;
		if(a[i]==3*a[p3]) p3++;
		if(a[i]==5*a[p5]) p5++;
		if(a[i]==7*a[p7]) p7++;
	}
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		if(n%10==1&&n%100!=11) printf("The %dst humble number is %d.\n",n,a[n]);
		else if(n%10==2&&n%100!=12) printf("The %dnd humble number is %d.\n",n,a[n]);
		else if(n%10==3&&n%100!=13) printf("The %drd humble number is %d.\n",n,a[n]);
		else printf("The %dth humble number is %d.\n",n,a[n]);
	}
    return 0;
}