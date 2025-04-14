#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
int cnt[MAX];
int main()
{
	int n,i,j,x,sum;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	vector<int> dp(1);
	dp[0]=1;
	sum=0;
	for(i=1;i<MAX;i++)
	{
		sum=sum/2+cnt[i];
		vector<int> newdp(sum+1,0);
		for(j=sum;j>=cnt[i];j--) newdp[j]=dp[2*(j-cnt[i])];
		for(j=sum-1;~j;j--) newdp[j]=(newdp[j]+newdp[j+1])%mod;
		dp=newdp;
	}
	printf("%d\n",dp[0]);
	return 0;
}
