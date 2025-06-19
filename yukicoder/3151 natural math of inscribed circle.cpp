#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	double a,b,c,s,t,r;
	scanf("%lf%lf%lf",&a,&b,&c);
	t=(a+b+c)/2;
	s=sqrt(t*(t-a)*(t-b)*(t-c));
	r=2*s/(a+b+c);
	printf("%.10f\n",r);
	return 0;
}

