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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=4000000;
const ll mod=1e6;
int main()
{
	ll x,y,a,b,ans;
	while(~scanf("%lld%lld",&x,&y))
	{
		a=x/5;
		b=y/5;
		ans=a*b;
		ans=ans+(a+(x%5>=1))*(b+(y%5>=4));
		ans=ans+(a+(x%5>=2))*(b+(y%5>=3));
		ans=ans+(a+(x%5>=3))*(b+(y%5>=2));
		ans=ans+(a+(x%5>=4))*(b+(y%5>=1));
		printf("%lld\n",ans);
	}
	return 0;
}