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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	ll a[66],ans[33],n,m,i,j,s;
	while(~scanf("%lld%lld",&n,&m))
	{
		mem(a,0);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<m;i++)
		{
			sort(a+1,a+1+n+i);
			s=0;
			for(j=1;j<=n+i;j++)
			{
				if(s+1<a[j])
				{
					a[n+i+1]=s+1;
					ans[i]=s+1;
					break;
				}
				s+=a[j];
			}
			if(a[n+i+1]==0)
			{
				a[n+i+1]=s+1;
				ans[i]=s+1;
			}
		}
		for(i=0;i<m;i++)
		{
			if(i==m-1) printf("%lld\n",ans[i]);
			else printf("%lld ",ans[i]);
		}
	}
	return 0;
}