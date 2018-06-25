////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-30 18:04:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5232
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
using namespace std; 
int main()
{
	int n,a,sum,i,j;
	while(cin>>n)
	{
		sum=2*n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a;
				sum+=a;
			}
		}
		cout<<sum<<endl;
	} 
	return 0;
}