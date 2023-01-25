#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=5000+10;
const ll mod=1e9+7;
/********************************* std-head *********************************/
int a[MAX];
ll dp[MAX],ans[MAX];
int main()
{
	int n,p,i,j;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]%=p;
	}
	mem(ans,0);
	mem(dp,0);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			dp[a[i]*a[j]%p]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<p;j++)
		{
			ans[(j+a[i])%p]+=dp[j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			ans[(a[i]*a[j]+a[i])%p]-=2;
		}
	}
	for(i=0;i<=p-1;i++) printf("%lld%c",ans[i]," \n"[i==p-1]);
	return 0;
}

