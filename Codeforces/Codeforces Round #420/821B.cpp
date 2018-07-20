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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=10000;
int main()
{
	ll m,b,ans,x,y;
	while(~scanf("%lld%lld",&m,&b))
	{
		ans=0;
		for(y=0;y<=b;y++)
		{
			x=m*b-y*m;
			ans=max(ans,(x+y)*(x+1)*(y+1)/2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}