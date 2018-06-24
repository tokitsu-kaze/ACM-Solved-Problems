////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-06 20:25:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1969
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#define pi 4*atan(1)
using namespace std;
int main()
{
	int t,n,m,i,count,r;
	double mid,lb,rb,s[10005],max;
	const double eps=1e-6;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>m>>n;
			max=INT_MIN;
			for(i=0;i<m;i++)
			{
				scanf("%d",&r);
				s[i]=pi*r*r;
				if(s[i]>max) max=s[i];
			}
			n++;
			lb=0;
			rb=max;
			while(rb-lb>eps)
			{
				mid=(lb+rb)/2;
				for(i=0,count=0;i<m;i++)
				{
					count+=(int)(s[i]/mid);
				}
				if(count<n) rb=mid;
				else if(count>=n) lb=mid;
			}
			printf("%.4lf\n",mid);
		}
	}
	return 0;
}