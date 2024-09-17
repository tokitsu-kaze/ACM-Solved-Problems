#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX],pre[MAX],suf[MAX];
int main()
{
	int n,i;
	ll ans,sum;
	scanf("%d",&n);
	memset(suf,0,sizeof suf);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		suf[a[i]]++;
	}
	ans=1LL*n*(n-1)*(n-2)/6;
	memset(pre,0,sizeof pre);
	sum=0;
	for(i=1;i<=n;i++)
	{
		sum-=1LL*pre[a[i]]*suf[a[i]];
		suf[a[i]]--;
		if(i>1 && i<n)
		{
			ans-=1LL*pre[a[i]]*(n-i);
			ans-=1LL*suf[a[i]]*(i-1);
			ans-=sum;
		}
		pre[a[i]]++;
		sum+=1LL*pre[a[i]]*suf[a[i]];
	}
	for(i=1;i<=200000;i++)
	{
		if(pre[i]>=3) ans+=1LL*pre[i]*(pre[i]-1)*(pre[i]-2)/6;
	}
	printf("%lld\n",ans);
	return 0;
}
