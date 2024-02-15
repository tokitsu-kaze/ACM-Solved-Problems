#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=(1<<10)+5;
ll dp[MAX][1010],fac[12];
int main()
{
	int t,n,i,j,k,d;
	ll ans;
	char s[15];
	fac[0]=1;
	for(i=1;i<=10;i++) fac[i]=fac[i-1]*i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",s,&d);
		n=strlen(s);
		for(i=0;i<(1<<n);i++)
		{
			for(j=0;j<d;j++)
			{
				dp[i][j]=0;
			}
		}
		dp[0][0]=1;
		for(i=0;i<(1<<n);i++)
		{
			for(j=0;j<n;j++)
			{
				if((i>>j)&1) continue;
				for(k=0;k<d;k++)
				{
					dp[i|(1<<j)][(k*10+s[j]-'0')%d]+=dp[i][k];
				}
			}
		}
		ans=dp[(1<<n)-1][0];
		map<char,int> mp;
		for(i=0;i<n;i++) mp[s[i]]++;
		for(auto &it:mp) ans/=fac[it.second];
		printf("%lld\n",ans);
	}
	return 0;
}
