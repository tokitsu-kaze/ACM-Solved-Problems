#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=9e6+10;
const int mod=998244353;
int dp[MAX],tag[MAX];
ll l[MAX],r[MAX];
int main()
{
	int m,i,a,b,ok,now;
	ll n,j;
	scanf("%lld%d%d%d",&n,&m,&a,&b);
	ok=1;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
		if(r[i]-l[i]>20) ok=0;
	}
	if(!ok) return 0*puts("No");
	if(a==b)
	{
		ok=1;
		for(i=1;i<=m;i++)
		{
			for(j=l[i];j<=r[i];j++)
			{
				if((j-1)%a==0) ok=0;
			}
		}
		if((n-1)%a) ok=0;
		if(ok) puts("Yes");
		else puts("No");
		return 0;
	}
	memset(tag,0,sizeof tag);
	now=1;
	r[0]=1;
	for(i=1;i<=m;i++)
	{
		now+=min(401LL,l[i]-r[i-1]);
		for(j=now;j<=now+(r[i]-l[i]);j++) tag[j]=1;
		now+=r[i]-l[i];
	}
	n=now+min(401LL,n-r[m]);
	dp[1]=1;
	for(i=2;i<=n;i++)
	{
		dp[i]=0;
		if(tag[i]) continue;
		for(j=max(1,i-b);j<=i-a;j++) dp[i]|=dp[j];
	}
	if(dp[n]) puts("Yes");
	else puts("No");
	return 0;
}
