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
const int MAX=1e5+10;
const ll mod=1e9+7;
/********************************* std-head *********************************/
int cnt[MAX],a[MAX];
int main()
{
	int t,n,i,k,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mem(cnt,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		VI res;
		for(i=1;i<=MAX-10;i++)
		{
			if(cnt[i]) res.pb(cnt[i]);
		}
		sort(all(res));
		ans=0;
		for(k=1,i=0;k<=n;k++)
		{
			while(i<sz(res)&&res[i]<=k)
			{
				ans+=res[i];
				i++;
			}
			if(i==n) printf("%d\n",ans);
			else printf("%d\n",(sz(res)-i)*(k-1)+ans);
		}
	}
	return 0;
}

