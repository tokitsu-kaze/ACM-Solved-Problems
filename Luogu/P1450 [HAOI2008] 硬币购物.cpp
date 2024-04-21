#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int c[5],d[5];
ll dp[MAX],ans;
void dfs(int x,ll s,int f)
{
	if(s<0) return;
	if(x==4)
	{
		ans+=f*dp[s];
		return;
	}
	dfs(x+1,s-1LL*c[x]*(d[x]+1),f*(-1));
	dfs(x+1,s,f);
}
int main()
{
	int n,i,j,s;
	for(i=0;i<4;i++) scanf("%d",&c[i]);
	dp[0]=1;
	for(i=0;i<4;i++)
	{
		for(j=c[i];j<MAX;j++) dp[j]+=dp[j-c[i]];
	}
	scanf("%d",&n);
	while(n--)
	{
		for(i=0;i<4;i++) scanf("%d",&d[i]);
		scanf("%d",&s);
		ans=0;
		dfs(0,s,1);
		printf("%lld\n",ans);
	}
	return 0;
}
