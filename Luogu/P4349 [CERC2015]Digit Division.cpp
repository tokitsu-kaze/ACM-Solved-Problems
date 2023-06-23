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
const int MAX=3e5+10;
const ll mod=1e9+7;
char a[MAX];
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ll n,m,i,cnt,now;
	while(~scanf("%lld%lld",&n,&m))
	{
		scanf("%s",a);
		cnt=0;
		now=0;
		for(i=0;i<n;i++)
		{
			now=now*10+a[i]-'0';
			now%=m;
			if(now==0) cnt++;
		}
		if(cnt==0||now) puts("0");
		else printf("%lld\n",pow2(2,cnt-1));
	}
	return 0;
}
// gym 101480D 
