////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-21 19:41:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5170
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1704KB
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
int main()
{
	int ans;
	double a,b,c,d;
	while(~scanf("%lf%lf%lf%lf",&a,&b,&c,&d))
	{
		ans=sgn(b*log(a)-d*log(c));
		if(ans==1) puts(">");
		else if(ans==-1) puts("<");
		else puts("=");
	}
	return 0;
}