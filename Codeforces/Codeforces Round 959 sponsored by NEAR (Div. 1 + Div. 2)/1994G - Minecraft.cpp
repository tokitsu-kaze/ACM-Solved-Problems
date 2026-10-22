#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
char s[MAX];
int cnt[MAX],tar[MAX];
int main()
{
	int T,n,k,i,j,f,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(i=1;i<=k;i++)
		{
			tar[i]=s[k-i+1]-'0';
			cnt[i]=0;
		}
		for(j=1;j<=n;j++)
		{
			scanf("%s",s+1);
			for(i=1;i<=k;i++) cnt[i]+=s[k-i+1]-'0';
		}
		vector<vector<int>> dp(k+1),pre(k+1);
		dp[0].resize(n+1,0);
		dp[0][0]=1;
		pre[0].resize(n+1,-1);
		for(i=1;i<=k;i++)
		{
			dp[i].resize(n+1,0);
			pre[i].resize(n+1,-1);
			for(j=0;j<=n;j++)
			{
				if(!dp[i-1][j]) continue;
				if(j+cnt[i]-tar[i]>=0 && (j+cnt[i]-tar[i])%2==0)
				{
					dp[i][(j+cnt[i]-tar[i])/2]=1;
					pre[i][(j+cnt[i]-tar[i])/2]=j;
				}
				if(j+n-cnt[i]-tar[i]>=0 && (j+n-cnt[i]-tar[i])%2==0)
				{
					dp[i][(j+n-cnt[i]-tar[i])/2]=1;
					pre[i][(j+n-cnt[i]-tar[i])/2]=j;
				}
			}
		}
		if(!dp[k][0])
		{
			puts("-1");
			continue;
		}
		now=0;
		for(i=k;i;i--)
		{
			if(now*2==pre[i][now]+cnt[i]-tar[i]) s[i]='0';
			else if(now*2==pre[i][now]+n-cnt[i]-tar[i]) s[i]='1';
			else assert(0);
			now=pre[i][now];
		}
		reverse(s+1,s+1+k);
		s[k+1]='\0';
		puts(s+1);
	}
	return 0;
}
/*
dp[i][j] 表示从低到高的第 i 位，向后一位进位为 j 的可行性。
发现进位：第一次最多为 n/2，第二次最多为 n/2+n/4...
即，每次进位不超过 n。
枚举第 i 位是 0 还是 1，直接做即可。这有 *2600 ？
*/
