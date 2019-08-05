////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-06 16:28:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2899
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1648KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
double fx(double x,double y)
{
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
int main()
{
	int n;
	double y,lm,rm,l,r;
	const double eps=1e-6;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>y;
			l=0;
			r=100;
			while(r-l>eps)
			{
				lm=(2*l+r)/3;
				rm=(l+2*r)/3;
				if(fx(lm,y)<fx(rm,y)) r=rm;
				else l=lm;
			}
			printf("%.4lf\n",fx(l,y));
		}
	}
	return 0;
}