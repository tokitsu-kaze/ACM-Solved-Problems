////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-30 17:53:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5630
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
using namespace std; 
int main()
{
	int n,a,b;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>a>>b;
			cout<<a/2+b/2<<endl;
		}
	} 
	return 0;
}