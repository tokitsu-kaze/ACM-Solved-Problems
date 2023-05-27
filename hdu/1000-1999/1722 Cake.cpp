////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-30 19:26:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1722
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<a+b-gcd(a,b)<<endl;
	} 
	return 0;
}