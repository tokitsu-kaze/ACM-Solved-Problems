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
int a[4040],b[4040],c[4040],d[4040];
int res[4040*4040];
void go()
{
	int n,tot,i,j,x;
	ll ans;
	while(~scanf("%d",&n))
	{
		assert(n<=2500);
		for(i=1;i<=n;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		tot=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				res[++tot]=a[i]+b[j];
			}
		}
		sort(res+1,res+1+tot);
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				x=c[i]+d[j];
				ans+=upper_bound(res+1,res+1+tot,-x)-lower_bound(res+1,res+1+tot,-x);
			}
		}
		printf("%lld\n",ans);
	}
}
