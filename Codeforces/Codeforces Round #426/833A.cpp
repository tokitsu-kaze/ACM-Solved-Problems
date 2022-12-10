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
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	ll t,a,b,c;
	while(~scanf("%lld",&t))
	{
		while(t--)
		{
			scanf("%lld%lld",&a,&b);
			c=(ll)(pow(a*b,1.0/3)+0.5);
			if(c*c*c==a*b&&a%c==0&&b%c==0) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
/*
10000
1 1
2 4
75 45
8 8
16 16
247 994
1000000000 1000000
*/