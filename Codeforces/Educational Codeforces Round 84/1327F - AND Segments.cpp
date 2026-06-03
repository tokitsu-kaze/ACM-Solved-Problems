#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
int l[MAX],r[MAX],x[MAX],n,k,m;
int tag[MAX],pos[MAX],dp[MAX];
int cal(int s)
{
	int i,lst,sum;
	memset(tag,0,sizeof tag);
	memset(pos,0,sizeof pos);
	for(i=1;i<=m;i++)
	{
		if((x[i]>>s)&1)
		{
			tag[l[i]]++;
			tag[r[i]+1]--;
		}
		else pos[r[i]]=max(pos[r[i]],l[i]);
	}
	for(i=1;i<=n;i++)
	{
		tag[i]+=tag[i-1];
		pos[i]=max(pos[i],pos[i-1]);
//		printf("%d %d %d %d\n",s,i,tag[i],pos[i]);
	}
	sum=1;
	dp[0]=1;
	lst=0;
	for(i=1;i<=n;i++)
	{
		if(tag[i]) dp[i]=0;
		else dp[i]=sum;
		sum=(sum+dp[i])%mod;
		while(lst<pos[i])
		{
			sum=(sum-dp[lst]+mod)%mod;
			dp[lst]=0;
			lst++;
		}
//		printf("%d %d %d\n",i,s,sum);
	}
	return sum;
}
int main()
{
	int i;
	ll ans;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=m;i++) scanf("%d%d%d",&l[i],&r[i],&x[i]);
	ans=1;
	for(i=0;i<k;i++) ans=ans*cal(i)%mod;
	printf("%lld\n",ans);
	return 0;
}
/*
每一位独立，拆位转化成填0/1，最后再把方案数乘起来。
限制转化成，区间中一些位必须填1，其他每个位在区间中至少有1个0。
考虑多个区间时，至少有1个0的限制该怎么表示。
设pos[i]为在i之前至少填0的最晚一个位置，即 r<=i 中 max{l}。
考虑dp[i][j]表示填了前i个，上一个0在j。
- 如果当前填1：j<0，dp[i][j]=0；pos[i]<=j<i，dp[i][j]=dp[i-1][j]；
- 如果当前填0，即j=i：
如果位置i强制填1，则dp[i][i]=0；
否则，dp[i][i]=sum{dp[i-1][pos[i]..i-1]}
发现i这一维可以省去，pos[i]是单调的可以双指针，求和这一步实际上是求整个dp的sum。
*/
