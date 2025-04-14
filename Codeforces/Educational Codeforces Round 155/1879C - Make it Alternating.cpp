#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
ll fac[MAX];
char s[MAX];
int main()
{
	int T,n,i,cnt,now;
	ll ans;
	fac[0]=1;
	for(i=1;i<MAX;i++) fac[i]=fac[i-1]*i%mod;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		cnt=0;
		ans=1;
		now=1;
		for(i=2;i<=n;i++)
		{
			if(s[i]!=s[i-1])
			{
				cnt+=now-1;
				ans=ans*now%mod;
				now=1;
			}
			else now++;
		}
		cnt+=now-1;
		ans=ans*now%mod;
		ans=ans*fac[cnt]%mod;
		printf("%d %lld\n",cnt,ans);
	}
	return 0;
}

