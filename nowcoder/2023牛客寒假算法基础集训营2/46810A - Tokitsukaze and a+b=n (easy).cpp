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
const int MAX=4e5+10;
const ll mod=998244353;
/********************************* std-head *********************************/
int main()
{
	int T;
	int n,l1,r1,l2,r2,ans,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%d%d",&l1,&r1);
		scanf("%d%d",&l2,&r2);
		ans=0;
		for(i=l1;i<=r1;i++)
		{
			if(n-i>=l2&&n-i<=r2) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}


