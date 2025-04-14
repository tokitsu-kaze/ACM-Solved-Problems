#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=998244353;
int dp[2][MAX];
int main()
{
	int T,s,k,i,j,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&s,&k);
		if(s%k==0)
		{
			printf("%d\n",k);
			continue;
		}
		if(s>k*k)
		{
			printf("%d\n",max(1,k-2));
			continue;
		}
		f=0;
		for(i=0;i<=s;i++) dp[f][i]=0;
		dp[f][0]=1;
		while(1)
		{
			f^=1;
			for(i=0;i<=s;i++) dp[f][i]=0;
			if(!f)
			{
				for(i=s-k;~i;i--) dp[f][i]=dp[!f][i+k]|dp[f][i+k];
			}
			else
			{
				for(i=k;i<=s;i++) dp[f][i]=dp[!f][i-k]|dp[f][i-k];
			}
			if(dp[f][s]) break;
			k=max(1,k-1);
//			for(i=0;i<=s;i++) cout<<i<<" "<<dp[f][i]<<endl;
		}
		printf("%d\n",k);
	}
	return 0;
}
