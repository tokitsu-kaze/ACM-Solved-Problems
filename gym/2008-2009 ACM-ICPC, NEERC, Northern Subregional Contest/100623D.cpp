#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int a[MAX],b[MAX];
int main()
{
	freopen("deposits.in","r",stdin);
	freopen("deposits.out","w",stdout);
	int n,m,i,j,x;
	ll ans;
	while(~scanf("%d",&n))
	{
		mem(a,0);
		mem(b,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			b[x]++;
		}
		ans=(ll)b[1]*n;
		for(i=2;i<=1e6;i++)
		{
			if(b[i])
			{
				for(j=i;j<=1e6;j+=i)
				{
					ans+=(ll)b[i]*a[j];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}