////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-31 22:25:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2548
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1640KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	double a,b,c,d;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>a>>b>>c>>d;
			printf("%.3lf\n",1.0*d/(a+b)*c);
		}
	}
	return 0;
}