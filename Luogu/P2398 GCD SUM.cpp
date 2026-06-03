#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll cnt[MAX];
int main()
{
	int n,i,j;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) cnt[i]=1;
	for(i=1;i<=n;i++)
	{
		for(j=i+i;j<=n;j+=i) cnt[i]+=cnt[j];
	}
	for(i=n;i;i--)
	{
		cnt[i]=cnt[i]*cnt[i];
		for(j=i+i;j<=n;j+=i) cnt[i]-=cnt[j];
	}
	ans=0;
	for(i=1;i<=n;i++) ans+=i*cnt[i];
	printf("%lld\n",ans);
	return 0;
}

