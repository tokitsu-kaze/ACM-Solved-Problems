////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-10 14:56:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2374
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=1e6+10;
int main()
{
	ll n,i,a[1111],ans,now;
	while(~scanf("%lld",&n)&&n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		now=0;
		ans=0;
		for(i=n-1;i>=0;i--)
		{
			a[i]+=now;
			ans+=a[i];
			now+=a[i]; 
		}
		printf("%lld\n",ans);
	}
	return 0;
}