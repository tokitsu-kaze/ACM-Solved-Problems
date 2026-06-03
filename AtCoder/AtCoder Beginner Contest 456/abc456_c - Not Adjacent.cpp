#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
char s[MAX];
int main()
{
	int n,i,cnt;
	ll ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=0;
	cnt=1;
	for(i=2;i<=n;i++)
	{
		if(s[i]==s[i-1])
		{
			ans+=1LL*cnt*(cnt+1)/2;
			cnt=1;
		}
		else cnt++;
	}
	ans+=1LL*cnt*(cnt+1)/2;
	printf("%lld\n",ans%mod);
	return 0;
}
