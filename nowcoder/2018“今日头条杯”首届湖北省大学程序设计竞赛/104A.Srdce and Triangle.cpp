#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
		if(b<60||c<60)
		{
			puts("-1 -1 -1");
		}
		else
		{
			double t[3];
			t[0]=b-60;
			t[1]=c-60;
			t[2]=300-c-b;
			sort(t,t+3);

			printf("%.4lf %.4lf %.4lf\n",t[0],t[1],t[2]);
		}
	}


}

