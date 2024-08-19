#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX],b[MAX],id[MAX];
ll dp[2][12];
int main()
{
	int n,i,j,k,f;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		id[i]=i;
	}
	sort(id+1,id+1+n,[&](int x,int y){
		return (a[x]+b[x])*a[y]+b[y]>(a[y]+b[y])*a[x]+b[x];
	});
	f=0;
	memset(dp[f],-0x3f,sizeof dp[f]);
	dp[f][0]=1;
	for(i=1;i<=n;i++)
	{
		f^=1;
		memset(dp[f],-0x3f,sizeof dp[f]);
		dp[f][0]=1;
		for(j=1;j<=k;j++)
		{
			dp[f][j]=dp[!f][j];
			if(dp[!f][j-1]>0) dp[f][j]=max(dp[f][j],a[id[i]]*dp[!f][j-1]+b[id[i]]);
		}
	}
	printf("%lld\n",dp[f][k]);
	return 0;
}

