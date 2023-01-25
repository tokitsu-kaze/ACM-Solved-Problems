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
const int MAX=2e5+10;
const ll mod=998244353;
/********************************* std-head *********************************/
int v[MAX],h[MAX];
int main()
{
	int n,i,f;
	ll ans;
	scanf("%d",&n);
	h[1]=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&f);
		h[i]=h[f]+1;
	}
	for(i=1;i<=n;i++) scanf("%d",&v[i]);
	sort(v+1,v+1+n);
	sort(h+1,h+1+n);
	ans=0;
	for(i=n;i;i--) ans+=1ll*h[i]*v[i];
	printf("%lld\n",ans);
	return 0;
}

