#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e4+10;
int b[MAX],c[MAX],dp[MAX],w[MAX];
int main()
{
	int T,n,k,i,j,ans;
	for(i=2;i<=1000;i++) w[i]=INF;
	w[1]=0;
	for(i=1;i<=1000;i++)
	{
		for(j=1;j<=i;j++) w[i+i/j]=min(w[i+i/j],w[i]+1);
//		cout<<i<<" "<<w[i]<<endl;
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) scanf("%d",&c[i]);
		if(k>2e4)
		{
			ans=0;
			for(i=1;i<=n;i++) ans+=c[i];
			printf("%d\n",ans);
			continue;
		}
		memset(dp,0,sizeof dp);
		for(i=1;i<=n;i++)
		{
			for(j=k;j>=w[b[i]];j--)
			{
				dp[j]=max(dp[j],dp[j-w[b[i]]]+c[i]);
			}
		}
		ans=0;
		for(i=0;i<=k;i++) ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
