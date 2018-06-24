////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-31 21:54:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2551
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1584KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m,i;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>m;
			for(i=1;;i++)
			{
				if(1.0*i*i*(i+1)*(i+1)/4>=m) break;
			}
			cout<<i<<endl;
		}
	}
	return 0;
}