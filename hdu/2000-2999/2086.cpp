////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-20 16:24:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2086
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1712KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
using namespace std;
//¹«Ê½a1=(n*a1+an1-2*(n*c1+(n-1)*c2+....+cn))/(n+1)
int main ()
{
    int n,i,j;
    double c[3001],sum,a0,an1;
    while(cin>>n)
    {
		cin>>a0>>an1;
		sum=0;
        for(i=0,j=n;i<n;i++,j--)
        {
			scanf("%lf",&c[i]);
			sum+=j*c[i];
		}
		printf("%.2lf\n",(n*a0+an1-2*sum)/(n+1));
    }
    return 0;
}