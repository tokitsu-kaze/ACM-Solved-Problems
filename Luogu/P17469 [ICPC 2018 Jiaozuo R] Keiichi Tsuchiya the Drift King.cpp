#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
const double eps=1e-7;
int sgn(double x)
{
	if(abs(x)<eps) return 0;
	else return x>0?1:-1;
}
double sqr(double x) {return x*x;}
int main()
{
	int T,a,b,r,d;
	double d_rad,phi;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&r,&d);
		d_rad=d*acos(-1)/180;
		phi=atan2(b,r+a);
		if(sgn(d_rad-phi)>=0) printf("%.12f\n",sqrt(sqr(r+a)+sqr(b))-r);
		else printf("%.12f\n",(r+a)*cos(d_rad)+b*sin(d_rad)-r);
	}
	return 0;
}
