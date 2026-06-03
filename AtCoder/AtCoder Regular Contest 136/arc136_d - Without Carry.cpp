#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int V=1e6;
const int MAX=V+10;
int dp[MAX],a[MAX];
int sd[7]={1,10,100,1000,10000,100000,1000000};
int main()
{
	int n,i,j,x,ok;
	ll ans;
	scanf("%d",&n);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[a[i]]++;
	}
	for(j=0;j<6;j++)
	{
		for(i=0;i<=V;i++)
		{
			if(i%sd[j+1]>=sd[j]) dp[i]+=dp[i-sd[j]];
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=dp[V-a[i]-1];
		ok=1;
		x=a[i];
		while(x)
		{
			if(x%10>=5) ok=0;
			x/=10;
		}
		ans-=ok;
	}
	printf("%lld\n",ans/2);
	return 0;
}
