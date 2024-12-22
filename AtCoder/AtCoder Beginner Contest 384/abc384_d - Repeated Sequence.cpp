#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
const int mod=998244353;
ll a[MAX],bit[MAX];
int main()
{
	int n,i,ok;
	ll s;
	scanf("%d%lld",&n,&s);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=n+1;i<=2*n;i++) a[i]=a[i-n];
	bit[0]=0;
	for(i=1;i<=2*n;i++) bit[i]=bit[i-1]+a[i];
	s%=bit[n];
	map<ll,int> mp;
	mp[0]=1;
	ok=0;
	for(i=1;i<=2*n;i++)
	{
		if(mp.count(bit[i]-s)) ok=1;
		mp[bit[i]]=1;
	}
	if(ok||s==0) puts("Yes");
	else puts("No");
	return 0;
}
