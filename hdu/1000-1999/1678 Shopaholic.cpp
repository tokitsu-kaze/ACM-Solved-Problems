////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 15:42:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1678
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int t,n,i,a[20001],sum;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			sum=0;
			cin>>n;
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			sort(a,a+n,cmp);
			for(i=0;i<n;i++)
			{
				if((i+1)%3==0)sum+=a[i];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}