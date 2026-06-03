#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int tag[MAX];
ll cnt[MAX];
int main()
{
	int T,n,i,j,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) tag[i]=cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			tag[x]=1;
			cnt[x]++;
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+i;j<=n;j+=i)
			{
				cnt[i]+=cnt[j];
				tag[j]|=tag[i];
			}
		}
		for(i=1;i<=n;i++) cnt[i]=cnt[i]*(cnt[i]-1)/2;
		for(i=n;i;i--)
		{
			for(j=i+i;j<=n;j+=i) cnt[i]-=cnt[j];
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(!tag[i]) ans+=cnt[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
题意是不存在一个k使得ak是gcd(ai,aj)的因数。
对k的倍数做标记，然后枚举k，
问题转化成求(i,j)数量使得gcd(ai,aj)=k。
经典问题，倒着容斥一下即可。
*/
