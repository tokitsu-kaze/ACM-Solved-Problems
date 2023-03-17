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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll n,k,i,cnt1,cnt2,a;
	while(~scanf("%lld%lld",&n,&k))
	{
		cnt1=cnt2=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a);
			if(a<=k) cnt1++;
			else
			{
				cnt2+=a/(2*k)+(a%(2*k)>k);
				if(a%(2*k)) cnt1+=(a%(2*k)<=k);
			}
		}
		printf("%lld\n",cnt1/2+cnt1%2+cnt2);
	}
	return 0;
}