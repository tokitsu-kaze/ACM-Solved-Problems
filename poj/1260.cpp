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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	int t,n,i,j,dp[111],cnt,a[111],b[111],bit[111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		dp[0]=bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			bit[i]=bit[i-1]+a[i];
			dp[i]=(bit[i]+10)*b[i];
			for(j=1;j<i;j++) dp[i]=min(dp[i],dp[j]+(bit[i]-bit[j]+10)*b[i]);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}