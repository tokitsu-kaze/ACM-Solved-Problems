////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 14:03:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6216
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:1668KB
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
const long double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int t,flag;
	ll x,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&x);
		i=1;
		flag=0;
		while(1)
		{
			if((i+1)*(i+1)*(i+1)-i*i*i==x)
			{
				flag=1;
				break;
			}
			if((i+1)*(i+1)*(i+1)-i*i*i>x) break;
			i++;
		}
		if(flag) puts("YES");
		else puts("NO"); 
	}
	return 0;
}