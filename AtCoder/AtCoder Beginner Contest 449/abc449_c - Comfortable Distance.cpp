#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
char s[MAX];
int main()
{
	int n,l,r,i,j,cnt[26];
	ll ans;
	scanf("%d%d%d",&n,&l,&r);
	scanf("%s",s+1);
	ans=0;
	memset(cnt,0,sizeof cnt);
	for(j=1,i=1;j<=n;j++)
	{
		while(i<j && j-i>r)
		{
			cnt[s[i]-'a']--;
			i++;
		}
		ans+=cnt[s[j]-'a'];
		cnt[s[j]-'a']++;
	}
	memset(cnt,0,sizeof cnt);
	for(j=1,i=1;j<=n;j++)
	{
		while(i<j && j-i>l-1)
		{
			cnt[s[i]-'a']--;
			i++;
		}
		ans-=cnt[s[j]-'a'];
		cnt[s[j]-'a']++;
	}
	printf("%lld\n",ans);
	return 0;
}
