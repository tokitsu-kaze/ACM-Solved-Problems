#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int n,i;
	ll ans,sum[26],cnt[26];
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=0;
	memset(sum,0,sizeof sum);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		ans+=cnt[s[i]-'A']*i-sum[s[i]-'A'];
		cnt[s[i]-'A']++;
		sum[s[i]-'A']+=i+1;
	}
	printf("%lld\n",ans);
	return 0;
}
