////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-01 16:22:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1572KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,u,d,min;
	while(cin>>n>>u>>d)
	{
		if(n+u+d==0) break;
		for(min=0;;min+=2)
		{
			if(n-u<=0) break;
			n-=u-d;
		}
		cout<<min+1<<endl;
	}
	return 0;
}