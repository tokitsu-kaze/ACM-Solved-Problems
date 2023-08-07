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
const int mod=1000000000+7;
int main()
{
	ll n,m;
	while(~scanf("%lld%lld",&n,&m))
	{
		if(n>=m/2) printf("%lld\n",m/2);
		else printf("%lld\n",(n*2+m)/4);
	}
	return 0;
}
