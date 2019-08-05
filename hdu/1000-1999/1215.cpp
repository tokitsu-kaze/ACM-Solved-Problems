////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-30 22:35:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:436MS
////Run memory:3544KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 500000+5
using namespace std;
int a[maxn];
int main()
{
	int n,i,j,m;
	a[0]=a[1]=1;
	for(i=1;i<maxn/2;i++)
	{
		for(j=i*2;j<maxn;j+=i)
		{
			a[j]+=i;
		}
	}
	while (cin>>n)
	{
		while(n--)
		{
			cin>>m;
			cout<<a[m]<<endl;
		}
	}
	return 0;
}