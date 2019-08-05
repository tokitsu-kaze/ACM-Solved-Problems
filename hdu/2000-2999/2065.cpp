////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-06 14:36:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2065
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1576KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
ll pow2(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%100;
		a=a*a%100;
		b>>=1;
	}
	return ans;
}
int main()
{
    ll t,n,i;
	while(scanf("%I64d",&t)&&t)
	{
		for(i=1;i<=t;i++)
		{
			scanf("%I64d",&n);
			printf("Case %I64d: %I64d\n",i,(pow2(4,n-1)+pow2(2,n-1))%100);
		}
		puts("");
	} 
    return 0;
}
