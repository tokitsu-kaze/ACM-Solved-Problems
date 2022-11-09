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
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	ll n,m,a;
	while(~scanf("%lld%lld%lld",&n,&m,&a))
	{
		if(n<=a&&m<=a)
		{
			puts("1");
			continue;
		}
		if(n%a&&n/a) n=n/a+1;
		else n/=a;
		if(m%a&&m/a) m=m/a+1;
		else m/=a;
		printf("%lld\n",n*m);
	}
	return 0;
}