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
	int a,b,c,i,ans;
	while(~scanf("%d%d",&a,&b))
	{
		c=min(a,b);
		ans=1;
		for(i=1;i<=c;i++)
		{
			ans*=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}