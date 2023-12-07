#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long double a,b,c,x;
		scanf("%LF%LF%LF%LF",&a,&b,&c,&x);
		x/=100;
		long double nextx=b-x*b;
		long double nexty=a*x;
		long double X=(b+c)*2;
		long double Y=a;
		//double ans= sqrt((X-nextx)*(X-nextx)+ (Y-nexty)*(Y-nexty)) +sqrt(a*a+b*b)*(x);
		long double ans1=sqrt((X-b)*(X-b) + (Y)*(Y));

		X=x*b;
		Y=a-x*a;
		nextx=b+2*c;
		nexty=0;
		long double ans2=sqrt((X-nextx)*(X-nextx) + (Y)*(Y));
		printf("%.10Lf\n",ans1+ans2+sqrt(a*a+b*b)*(x));
	}

	return 0;
}