#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],cnt[MAX];
int main()
{
	int T,n,k,i,j,ok;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(cnt[i]%k) ok=0;
			cnt[i]/=k;
		}
		if(ok==0)
		{
			puts("0");
			continue;
		}
		ans=0;
		for(i=1,j=0;i<=n;i++)
		{
			while(j<n)
			{
				if(cnt[a[j+1]]==0) break;
				j++;
				cnt[a[j]]--;
			}
			ans+=j-i+1;
			cnt[a[i]]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
