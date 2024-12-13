#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int a[MAX];
ll dp[MAX],tmpdp[MAX],mxdp,delta;
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(tmpdp,-0x3f,sizeof tmpdp);
		dp[0]=dp[1]=0;
		mxdp=delta=0;
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			dp[i]=max(mxdp,tmpdp[a[i]]+delta+a[i]);
			if(a[i]==a[i-1]) delta+=a[i];
			tmpdp[a[i-1]]=max(tmpdp[a[i-1]],dp[i]-delta);
			tmpdp[a[i]]=max(tmpdp[a[i]],dp[i]-delta);
			mxdp=max(mxdp,dp[i]);
//			printf("%d %lld\n",i,dp[i]);
		}
		printf("%lld\n",mxdp);
	}
	return 0;
}

