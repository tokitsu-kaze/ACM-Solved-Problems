
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
const int MAX=1000000+10;
const ll mod=10000;
int main()
{
	int t,i,a[22],cas;
	scanf("%d",&t);
	while(t--)
	{
		mem(a,0);
		scanf("%d",&cas);
		for(i=0;i<10;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+10);
		printf("%d %d\n",cas,a[7]);
	}
	return 0;
}