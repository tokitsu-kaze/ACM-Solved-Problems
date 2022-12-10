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
const int MAX=1e3+10;
const ll mod=1e6;
int main()
{
	ll n,k,a[MAX],i,ans;
	while(~scanf("%lld%lld",&n,&k))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		ans=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>k&&a[i]<=k*2) k=a[i];
			else if(a[i]>k*2)
			{
				while(a[i]>k*2)
				{
					k*=2;
					ans++;
				}
				if(k<a[i]) k=a[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}