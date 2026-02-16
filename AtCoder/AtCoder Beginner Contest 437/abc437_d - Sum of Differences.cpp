#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
int a[MAX],b[MAX];
ll sumb[MAX];
int main()
{
	int n,m,i,pos;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+1+m);
	sumb[0]=0;
	for(i=1;i<=m;i++) sumb[i]=sumb[i-1]+b[i];
	ans=0;
	for(i=1;i<=n;i++)
	{
		pos=upper_bound(b+1,b+1+m,a[i])-b;
		ans=(ans+1LL*a[i]*(pos-1)-sumb[pos-1]
				-1LL*a[i]*(m-pos+1)+sumb[m]-sumb[pos-1])%mod;
	}
	if(ans<0) ans+=mod;
	printf("%lld\n",ans);
	return 0;
}
