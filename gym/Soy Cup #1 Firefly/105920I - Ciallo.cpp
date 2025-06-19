#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char s[MAX],t[MAX];
int main()
{
	int T,i,n,m,cnta[26],cntb[26];
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		memset(cnta,0,sizeof cnta);
		memset(cntb,0,sizeof cntb);
		for(i=1;i<=n;i++) cnta[s[i]-'a']++;
		for(i=1;i<=m;i++) cntb[t[i]-'a']++;
		ans=1LL*(n+1)*(m+1)-1;
		for(i=0;i<26;i++) ans-=1LL*cnta[i]*cntb[i];
		printf("%lld\n",ans);
	}
	return 0;
}
