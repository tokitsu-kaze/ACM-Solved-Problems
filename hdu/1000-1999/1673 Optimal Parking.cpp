////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 15:31:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1673
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t,n,i,a[21];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			sort(a,a+n);
			cout<<(a[n-1]-a[0])*2<<endl;
		}
	}
	return 0;
}