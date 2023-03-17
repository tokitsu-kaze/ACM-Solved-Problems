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
const int MAX=1e5+10;
const ll mod=1e6;
int main()
{
	int n,i,a[MAX],ans[MAX],maxx;
	while(~scanf("%d",&n))
	{
		maxx=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=n-1;i>=0;i--)
		{
			if(i==n-1) ans[i]=0;
			else
			{
				if(a[i]>maxx) ans[i]=0;
				else ans[i]=maxx-a[i]+1;
			}
			maxx=max(maxx,a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(i==n-1) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}