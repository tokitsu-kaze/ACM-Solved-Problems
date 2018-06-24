////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-11 20:14:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4989
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1888KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 200+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	ll n,a[111],i,j,sum;
	set<ll> s;
	set<ll> ::iterator it;
	while(~scanf("%lld",&n))
	{
		s.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				s.insert(a[i]+a[j]);
			}
		}
		sum=0;
		for(it=s.begin();it!=s.end();it++)
		{
			sum+=(*it);
		}
		printf("%lld\n",sum);
	}
    return 0;
}