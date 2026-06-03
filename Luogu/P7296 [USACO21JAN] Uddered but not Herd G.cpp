#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<20)+10;
char ss[MAX];
int a[MAX],val[22][22],dp[MAX];
int main()
{
	int n,s,i,j,tot,to[333],sum;
	scanf("%s",ss);
	n=strlen(ss);
	memset(to,-1,sizeof to);
	tot=0;
	for(i=0;i<n;i++)
	{
		if(to[ss[i]]==-1) to[ss[i]]=tot++;
		a[i]=to[ss[i]];
	}
	assert(tot<=20);
	memset(val,0,sizeof val);
	for(i=1;i<n;i++) val[a[i-1]][a[i]]++;
	memset(dp,0x3f,sizeof dp);
	dp[0]=1;
	for(s=0;s<(1<<tot);s++)
	{
		for(i=0;i<tot;i++)
		{
			if(!((s>>i)&1)) continue;
			sum=0;
			for(j=0;j<tot;j++)
			{
				if(!((s>>j)&1)) continue;
				sum+=val[i][j];
			}
			dp[s]=min(dp[s],dp[s^(1<<i)]+sum);
		}
	}
	printf("%d\n",dp[(1<<tot)-1]);
	return 0;
}
/*
神秘题面，藏了范围 |字符集|<=20。
又是类似TSP问题，考虑状压dp。
考虑求出加入一个字符产生多少贡献。
对于原串中 s[i-1] 和 s[i]，如果前者>=后者，则贡献+1。
只考虑相邻字符，是因为关系是有传递性，
相隔远的字符贡献能被相邻字符表达出来。
然后直接状压dp就做完了。
*/
