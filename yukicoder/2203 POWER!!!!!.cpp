#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int n,i,j,cnt[11],sd;
	ll ans;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		sd=1;
		for(j=1;j<=8;j++)
		{
			sd*=a[i];
			ans+=1LL*sd*cnt[j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
