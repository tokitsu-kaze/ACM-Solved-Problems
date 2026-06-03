#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char s[MAX];
int main()
{
	int n,i,j,cnt[33];
	ll ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(cnt,0,sizeof cnt);
	ans=0;
	for(i=1;i<=n;i++) cnt[s[i]-'a']++;
	for(i=0;i<26;i++)
	{
		for(j=i+1;j<26;j++)
		{
			ans+=1LL*cnt[i]*cnt[j];
		}
	}
	for(i=0;i<26;i++)
	{
		if(cnt[i]>1)
		{
			ans++;
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
