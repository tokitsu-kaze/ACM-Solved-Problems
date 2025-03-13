#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int dp[MAX],tag[MAX];
int main()
{
	int l,s,t,m,i,j,p[105],now,ans;
	scanf("%d",&l);
	scanf("%d%d%d",&s,&t,&m);
	for(i=1;i<=m;i++) scanf("%d",&p[i]);
	if(s==t)
	{
		ans=0;
		for(i=1;i<=m;i++) ans+=(p[i]%s==0);
		printf("%d\n",ans);
		return 0;
	}
	sort(p+1,p+1+m);
	memset(tag,0,sizeof tag);
	now=0;
	p[0]=0;
	for(i=1;i<=m;i++)
	{
		now+=min(s*t+1,p[i]-p[i-1]);
		tag[now]=1;
	}
	l=min(l,now+s*t+1);
	dp[0]=0;
	for(i=1;i<=l+s*t+1;i++)
	{
		dp[i]=INF;
		for(j=max(0,i-t);j<=i-s;j++) dp[i]=min(dp[i],dp[j]+tag[i]);
	}
	ans=INF;
	for(i=l;i<=l+s*t+1;i++) ans=min(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
