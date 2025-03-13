#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
int a[MAX],sum[MAX];
int main()
{
	int T,n,i,j,pre[33][2],suf[33][2],pos;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(pre,0,sizeof pre);
		memset(suf,0,sizeof suf);
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]^a[i];
			for(j=0;j<=30;j++) suf[j][(sum[i]>>j)&1]++;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			pos=-1;
			for(j=0;j<=30;j++)
			{
				pre[j][(sum[i-1]>>j)&1]++;
				if(((a[i]>>j)&1)) pos=j;
			}
			ans+=1LL*pre[pos][0]*suf[pos][0];
			ans+=1LL*pre[pos][1]*suf[pos][1];
			for(j=0;j<=30;j++) suf[j][(sum[i]>>j)&1]--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
a[y] xor s[x-1] xor s[z] > s[z] xor s[x-1]
*/

