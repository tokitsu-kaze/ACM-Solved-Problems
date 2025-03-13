#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
int _dp[MAX][42];
char a[MAX],b[MAX];
const int delta=20;
int &dp(int x,int y){return _dp[x][x-y+delta];}
int main()
{
	int n,m,i,j,k;
	scanf("%d",&k);
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	if(abs(n-m)>k) return 0*puts("No");
	memset(_dp,0x3f,sizeof _dp);
	for(i=0;i<=min(n,k);i++) dp(i,0)=i;
	for(i=0;i<=min(m,k);i++) dp(0,i)=i;
	for(i=0;i<=n;i++)
	{
		for(j=max(1,i-k);j<=min(m,i+k);j++)
		{
			if(a[i]==b[j]) dp(i,j)=dp(i-1,j-1);
			else dp(i,j)=min({dp(i-1,j-1),dp(i,j-1),dp(i-1,j)})+1;
		}
	}
	if(dp(n,m)<=k) puts("Yes");
	else puts("No");
	return 0;
}
