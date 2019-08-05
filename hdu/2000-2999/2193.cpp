////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-02 09:17:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2193
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1668KB
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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e9+7;
int main()
{
	ll n,i,a[111];
	a[0]=1;
	a[1]=2;
	for(i=2;a[i-1]<=1e9;i++)
	{
		a[i]=a[i-1]+a[i-2]+1;
	}
	while(~scanf("%lld",&n)&&n)
	{
		i=0;
		while(a[i]<=n) i++;
		printf("%lld\n",i-1);
	}
	return 0;
}
//1 2 4 7 12 