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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<PII > v[111];
int dp[111][2222];
int main()
{
	int t,n,i,j,k,x,a,b,maxx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=0;
		for(i=1;i<=n;i++)
		{
			v[i].clear();
			scanf("%d",&x);
			while(x--)
			{
				scanf("%d%d",&a,&b);
				v[i].pb(MP(a,b));
				maxx=max(maxx,a);
			}
		}
		mem(dp,0x3f);
		for(i=0;i<sz(v[1]);i++) dp[1][v[1][i].fi]=min(dp[1][v[1][i].fi],v[1][i].se);
		for(i=2;i<=n;i++)
		{
			for(j=0;j<sz(v[i]);j++)
			{
				for(k=0;k<v[i][j].fi;k++)
				{
					dp[i][k]=min(dp[i][k],dp[i-1][k]+v[i][j].se);
				}
				for(k=v[i][j].fi;k<=maxx;k++)
				{
					dp[i][v[i][j].fi]=min(dp[i][v[i][j].fi],dp[i-1][k]+v[i][j].se);
				}
			}
		}
		double ans=0;
		for(i=0;i<=maxx;i++)
		{
			ans=max(ans,i*1.0/dp[n][i]);
		}
		printf("%.3f\n",ans);
	}
	return 0;
}