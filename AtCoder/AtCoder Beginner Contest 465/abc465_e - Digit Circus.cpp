#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
const int mod=998244353;
namespace DIGDP
{
	const int base=10;
	const int DIG=500+2;
	int p[DIG],tot;
	int dp[DIG][1<<11][3][2];
	ll dfs(int pos,int lead,int s,int ret,int f,int limt)
	{
		if(pos==-1)
		{
			int tmp=__builtin_popcount(s);
			int cnt=0;
			if(tmp==3) cnt++;
			cnt+=f;
			cnt+=(ret==0);
			return cnt==1;
		}
		if(!limt&&!lead&&dp[pos][s][ret][f]!=-1) return dp[pos][s][ret][f];
		int res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			int nexs=s;
			if(i==0)
			{
				if(lead&&i==0&&pos);
				else nexs|=(1<<i);
			}
			else nexs|=(1<<i);
			res+=dfs(pos-1,lead&&i==0&&pos,nexs,(ret*10+i)%3,f|(i==3),limt&&i==p[pos]);
			res%=mod;
		}
		if(!limt&&!lead) dp[pos][s][ret][f]=res;
		return res;
	}
	ll gao(char *s,int n)
	{
		memset(dp,-1,sizeof dp);
		tot=0;
		for(int i=n-1;~i;i--) p[tot++]=s[i]-'0';
		return dfs(tot-1,1,0,0,0,1);
	}
}
char s[MAX];
int main()
{
	int n;
	scanf("%s",s);
	n=strlen(s);
	printf("%d\n",(DIGDP::gao(s,n)-1+mod)%mod);
	return 0;
}
