#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#define MAX 50010
#define eps 1e-6
using namespace std;
double b[MAX],h[MAX],w[MAX],d[MAX];
int main()
{
	int t,n,i;
	double l,r,mid,max,sum,v;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			max=INT_MIN;
			sum=0;
			for(i=0;i<n;i++)
			{
				scanf("%lf%lf%lf%lf",&b[i],&h[i],&w[i],&d[i]);
				if(b[i]+h[i]>max) max=b[i]+h[i];
				sum+=h[i]*w[i]*d[i];
			}
			cin>>v;
			if(v>sum)
			{
				cout<<"OVERFLOW"<<endl;
				continue;
			}
			l=0;
			r=max;
			while(r-l>eps)
			{
				mid=(l+r)/2;
				for(i=0,sum=0;i<n;i++)
				{
					if(mid<b[i]) continue;
					if(mid>=b[i]+h[i]) sum+=h[i]*w[i]*d[i];
					else sum+=(mid-b[i])*w[i]*d[i];
				}
				if(sum>=v) r=mid;
				else if(sum<v) l=mid;
			}
			printf("%.2f\n",mid);
		}
	}
	return 0;
}