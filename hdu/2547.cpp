////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-31 22:17:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2547
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1640KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n;
	double x1,y1,x2,y2;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>x1>>y1>>x2>>y2;
			printf("%.1lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
		}
	}
	return 0;
}