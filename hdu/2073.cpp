////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 16:49:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2073
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1640KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
double dis(double x,double y)
{
	double ans=0,z;
	int i;
	z=sqrt(2.0);
	for(i=1;i<x+y;i++)
	{
		ans+=i*z;
	}
	ans+=x*z;
	for(i=0;i<x+y;i++)
	{
		ans+=sqrt(i*i+(i+1)*(i+1));
	}
	return ans;
}
int main()
{
    int t;
    double x1,y1,x2,y2;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>x1>>y1>>x2>>y2;
			printf("%.3lf\n",fabs(dis(x1,y1)-dis(x2,y2)));
		}
	}
    return 0;
}
