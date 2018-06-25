////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-10 20:08:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6195
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
const double eps=1e-6;
const int MAX=2e4+10;
const ll mod=1e9+7;
int main()
{
	ll m,k;
	while(~scanf("%lld%lld",&m,&k))
	{
		printf("%lld\n",(m-k)*k+k);	
	}
	return 0;
}