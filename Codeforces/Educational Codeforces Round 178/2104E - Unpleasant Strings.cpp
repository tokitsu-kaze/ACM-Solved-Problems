#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int K=26;
int nex[MAX][K];
void work(char *s,int len)
{
	for(int i=0;i<K;i++) nex[len][i]=nex[len+1][i]=len+1;
	for(int i=len;i;i--)
	{
		for(int j=0;j<K;j++)
		{
			nex[i-1][j]=nex[i][j];
		}
		nex[i-1][s[i]-'a']=i;
	}
}
char s[MAX],t[MAX];
int dp[MAX];
int main()
{
	int n,k,i,j,q,m,rt;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	work(s,n);
	dp[n+1]=0;
	for(i=n;i;i--)
	{
		dp[i]=INF;
		for(j=0;j<k;j++) dp[i]=min(dp[i],dp[nex[i][j]]+1);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",t+1);
		m=strlen(t+1);
		rt=0;
		for(i=1;i<=m;i++) rt=nex[rt][t[i]-'a'];
		printf("%d\n",dp[rt]);
	}
	return 0;
}

