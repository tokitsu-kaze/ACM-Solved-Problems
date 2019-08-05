////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-28 12:01:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1289
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1724KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e4+10;
const ll mod=1e9+7;
int main()
{
	int cnt;
	float x;
	while(~scanf("%f",&x))
	{
		cnt=0;
		while(fabs(x)>=2.0) x/=2.0,cnt++;
		while(fabs(x)<1.0) x*=2.0,cnt--;
		printf("%d %.6f\n",cnt,x);
	}
	return 0;
 }
