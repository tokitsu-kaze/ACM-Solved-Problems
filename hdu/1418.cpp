////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 11:29:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1418
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	__int64 a,b;
	while(cin>>a>>b)
	{
		if(a==0&&b==0) break;
		cout<<a+b-2<<endl;
	}
	return 0;
}