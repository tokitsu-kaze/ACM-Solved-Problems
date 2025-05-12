#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int b[MAX];
int main()
{
	int T,n,i,j;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ans=1;
		for(i=2,j=n/2+i-1;i<=n/2;i++,j++)
		{
			if(b[i-1]==b[i] && b[j]==b[j+1]) ans=ans*min(b[i],b[j])%mod*min(b[i],b[j])%mod;
			else if(b[i-1]==b[i] && b[j]>b[j+1])
			{
				// b[i]已被b[i-1]满足，考虑b[j]的限制
				if(b[i]>=b[j]) ans=ans*(2*b[j]-1)%mod;
				else ans=0;
			}
			else if(b[i-1]<b[i] && b[j]==b[j+1])
			{
				// b[j]已被b[j+1]满足，考虑b[i]的限制
				if(b[i]<=b[j]) ans=ans*(2*b[i]-1)%mod;
				else ans=0;
			}
			else if(b[i-1]<b[i] && b[j]>b[j+1])
			{
				// 都没被满足，此时b[i]必须等于b[j]，并且被它限制
				if(b[i]==b[j]) ans=ans*(2*b[i]-1)%mod;
				else ans=0;
			}
			else ans=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

