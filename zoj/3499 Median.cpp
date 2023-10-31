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
	int t,n,i;
	double a[511];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			mem(a,0);
			for(i=0;i<n;i++)
			{
				scanf("%lf",&a[i]);
			}
			sort(a,a+n);
			if(n%2) printf("%.3lf\n",a[n/2]);
			else printf("%.3lf\n",(a[n/2-1]+a[n/2])/2);
		}
	}
	return 0;
}