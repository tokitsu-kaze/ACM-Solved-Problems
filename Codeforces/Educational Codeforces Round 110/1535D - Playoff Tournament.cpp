#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<19)+10;
char s[MAX];
int dp[MAX];
void dfs(int l,int r,int id)
{
	if(l==r)
	{
		dp[id]=1;
		return;
	}
	int mid=(l+r)>>1;
	dfs(l,mid,id*2);
	dfs(mid+1,r,id*2+1);
	if(s[id]=='0') dp[id]=dp[id*2+1];
	else if(s[id]=='1') dp[id]=dp[id*2];
	else dp[id]=dp[id*2]+dp[id*2+1];
//	cout<<l<<" "<<r<<" "<<id<<" "<<dp[id]<<endl;
}
int main()
{
	int k,q,p;
	char ch[2];
	scanf("%d",&k);
	scanf("%s",s+1);
	reverse(s+1,s+(1<<k));
	dfs(1,(1<<k),1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%s",&p,ch);
		p=(1<<k)-p;
		s[p]=ch[0];
		while(p)
		{
			if(s[p]=='0') dp[p]=dp[p*2+1];
			else if(s[p]=='1') dp[p]=dp[p*2];
			else dp[p]=dp[p*2]+dp[p*2+1];
			p>>=1;
		}
		printf("%d\n",dp[1]);
	}
	return 0;
}

