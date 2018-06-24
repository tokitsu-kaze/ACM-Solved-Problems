////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-01 00:15:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1640KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double pow1(int n)
{
	double ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=0.95;
	}
	return ans;
}
int main()
{
	int n,i,m,k;
	double sum,a[101];
	while(cin>>n)
	{
		while(n--)
		{
			cin>>m;
			sum=k=0;
			for(i=0;i<m;i++)
			{
				cin>>a[i];
			}
			sort(a,a+m);
			for(i=m-1;i>=0;i--)
			{
				sum+=pow1(k++)*a[i];
			}
			printf("%.10lf\n",sum);
		}
	}
	return 0;
}