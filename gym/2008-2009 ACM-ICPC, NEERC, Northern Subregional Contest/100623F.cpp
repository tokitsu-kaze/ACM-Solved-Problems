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
ll a[MAX];
int main()
{
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	ll n,i,p,temp,s;
	while(~scanf("%lld",&n))
	{
		mem(a,0);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			temp=1;
			p=i;
			s=0;
			while(p%2==0)
			{
				p/=2;
				s+=a[i-temp];
				temp*=2;
			}
			a[i-1]-=s;
		}
		for(i=1;i<=n;i++)
		{
			if(i==n) printf("%lld\n",a[i]);
			else printf("%lld ",a[i]);
		}
	}
	return 0;
}