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
const int MAX=1e6+10;
const ll mod=1e9+7;
ll a[MAX],dp[MAX],minn[MAX];
int main()
{
	ll t,n,i,maxx,ans,dpmax;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		minn[0]=3e9;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			minn[i]=min(minn[i-1],a[i]);
		}
		mem(dp,0);
		maxx=a[n];
		ans=0;
		dpmax=0;
		for(i=n;i>=1;i--)
		{
			maxx=max(maxx,a[i]);
			dp[i]=maxx-a[i];
			dpmax=max(dpmax,dp[i]);
			ans=max(ans,a[i]-minn[i]+dpmax);
		}
		printf("%lld\n",ans);
	}
	return 0;
}