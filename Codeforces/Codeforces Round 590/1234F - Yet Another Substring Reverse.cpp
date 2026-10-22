#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<20)+10;
char s[MAX];
int tag[MAX],dp[MAX];
int main()
{
	int n,i,j,now,ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(dp,0,sizeof dp);
	memset(tag,0,sizeof tag);
	for(i=1;i<=n;i++)
	{
		now=0;
		for(j=i;j>=1;j--)
		{
			if(now&(1<<(s[j]-'a'))) break;
			now|=(1<<(s[j]-'a'));
			dp[now]=tag[now]=i-j+1;
		}
	}
	for(i=0;i<(1<<20);i++)
	{
		for(j=0;j<20;j++)
		{
			if((i>>j)&1) dp[i]=max(dp[i],dp[i^(1<<j)]);
		}
	}
	ans=0;
	for(i=0;i<(1<<20);i++)
	{
		if(!tag[i]) continue;
		ans=max(ans,tag[i]+dp[((1<<20)-1)^i]);
	}
	printf("%d\n",ans);
	return 0;
}
/*
相当于选两段不相交的前缀拼起来。
题目要求子串字母不能重复，所以符合条件的两个前缀肯定不相交。
dp[s] 表示状态为 s 时使用的最长子段，转移跑一个sosdp。
最后枚举合法子段，加上 dp[补集]，更新答案。
*/
