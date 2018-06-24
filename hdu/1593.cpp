////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-26 17:17:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1593
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1692KB
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
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	double r,r1,v1,v2,t1,t2;
	while(~scanf("%lf%lf%lf",&r,&v1,&v2))
	{
		r1=r/v2*v1;
		t1=(r-r1)/v1;
		t2=PI*r/v2;
		if(t1<t2) puts("Yes");
		else puts("No");
	}
	return 0;
}