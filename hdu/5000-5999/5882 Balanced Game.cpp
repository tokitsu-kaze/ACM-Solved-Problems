////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-30 17:49:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5882
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1580KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
using namespace std; 
int main()
{
	int n,a;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>a;
			if(a&1) cout<<"Balanced"<<endl;
			else cout<<"Bad"<<endl;
		}
	} 
	return 0;
}