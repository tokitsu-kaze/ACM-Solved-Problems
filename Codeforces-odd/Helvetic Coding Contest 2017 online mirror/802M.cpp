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
const int MAX=2200+10;
const ll mod=1e9+6;
int main()
{
	int n,k,a[MAX],i,sum;
	while(~scanf("%d%d",&n,&k))
	{
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		sum=0;
		for(i=0;i<k;i++)
		{
			sum+=a[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}