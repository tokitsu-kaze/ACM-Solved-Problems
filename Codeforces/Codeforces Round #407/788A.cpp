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
ll a[MAX],b[MAX],c[MAX];
int main()
{
	ll n,i,mb,mc,s;
	while(~scanf("%lld",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n-1;i++)
		{
			b[i]=abs(a[i]-a[i+1]);
			if(i%2) b[i]=-b[i];
			c[i]=-b[i];
		}
		mb=-INF;
		s=0;
		for(i=0;i<n-1;i++)
		{
			s+=b[i];
			if(s<0) s=0;
			mb=max(mb,s);
		}
		mc=-INF;
		s=0;
		for(i=0;i<n-1;i++)
		{
			s+=c[i];
			if(s<0) s=0;
			mc=max(mc,s);
		}
		printf("%lld\n",max(mb,mc));
	}
	return 0;
}