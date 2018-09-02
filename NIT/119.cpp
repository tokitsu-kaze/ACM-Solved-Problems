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
double v(double h,double r)
{
	return pi*r*r*h/3;
}
int main()
{
	int n,m,i,j,max;
	double sum1,sum2,mid,lb,rb,h[10001],r[10001];
	const double eps=1e-6;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>m;
			max=INT_MIN;
			sum1=0;
			for(i=0;i<m;i++)
			{
				scanf("%lf",&h[i]);
				if(h[i]>max) max=h[i];
			}
			for(i=0;i<m;i++)
			{
				scanf("%lf",&r[i]);
			}
			for(i=0;i<m;i++)
			{
				sum1+=v(h[i],r[i]);
			}
			//cout<<sum1<<endl;
			lb=0;
			rb=max;
			while(rb-lb>eps)
			{
				mid=(lb+rb)/2;
				for(i=0,sum2=0;i<m;i++)
				{
					if(mid>h[i]) continue;
					sum2+=v(h[i]-mid,((h[i]-mid)/h[i]*r[i]));
				}
				if(sum2>sum1/2) lb=mid;
				else if(sum2<sum1/2) rb=mid;
			}
			cout<<(int)mid<<endl;
		}
	}
	return 0;
}