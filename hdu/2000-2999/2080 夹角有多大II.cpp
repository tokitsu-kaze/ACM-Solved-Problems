////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-29 23:14:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2080
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1656KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std; 
int main()
{
	int t;
	double x1,y1,x2,y2;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>x1>>y1>>x2>>y2;
			printf("%.2lf\n",fabs((atan2(y1,x1)-atan2(y2,x2))*180/(4*atan(1))));
		}
	}
	return 0;
}