////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-05 22:04:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1411
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1708KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
double solve(double a,double b,double c,double d,double e,double f)
{
	return sqrt((4*a*a*b*b*c*c-a*a*(b*b+c*c-e*e)*(b*b+c*c-e*e)-b*b*(c*c+a*a-f*f)*(c*c+a*a-f*f)-c*c*(a*a+b*b-d*d)*(a*a+b*b-d*d)+(a*a+b*b-d*d)*(b*b+c*c-e*e)*(c*c+a*a-f*f)))/12;
}
int main()
{
	double a,b,c,d,e,f;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&f,&e))
	{
		printf("%.4lf\n",solve(a,b,c,d,e,f));
	}
	return 0;
}