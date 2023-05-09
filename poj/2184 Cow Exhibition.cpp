#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
#include <limits>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
using namespace std;
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
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int dp[200005];
void go()
{
	const int delta=100000;
	int n,i,j,s,f,ans;
	scanf("%d",&n);
	memset(dp,-0x3f,sizeof dp);
	dp[delta]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&s,&f);
		if(s<0)
		{
			for(j=0;j<=2*delta;j++)
			{
				if(j-s<0 || j-s>2*delta) continue;
				dp[j]=max(dp[j],dp[j-s]+f);
			}
		}
		else
		{
			for(j=2*delta;j>=0;j--)
			{
				if(j-s<0 || j-s>2*delta) continue;
				dp[j]=max(dp[j],dp[j-s]+f);
			}
		}
	}
	ans=0;
	for(i=delta;i<=2*delta;i++)
	{
	//	printf("%d %d\n",i,dp[i]);
		if(dp[i]>=0) ans=max(ans,i-delta+dp[i]);
	}
	printf("%d\n",ans);
}
