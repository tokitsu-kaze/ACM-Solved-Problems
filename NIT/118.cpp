#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
double area(double a,double b,double c,double d,double e,double f);
int main()
{
	int n,t,i;
	double x[1001],y[1001],sum;
	while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			sum=0;
			for(i=0;i<n;i++)
			{
				scanf("%lf%lf",&x[i],&y[i]);
				if(i>=2) sum+=area(x[0],y[0],x[i-1],y[i-1],x[i],y[i]);
			}
			printf("%.0lf\n",fabs(sum/2));
		}
    }
}
 
double area(double a,double b,double c,double d,double e,double f)
{
    return a*d+b*e+c*f-d*e-b*c-a*f;
}