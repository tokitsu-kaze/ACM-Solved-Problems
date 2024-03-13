#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
const int mod=10007;
short comb[MAX][105];
void init(int n,int m)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=m;j++)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
			if(comb[i][j]>=mod) comb[i][j]-=mod;
		}
	}
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
int main()
{
	int n,m,i,x,ans;
	scanf("%d%d",&n,&m);
	init(n,100);
	ans=1;
	while(m--)
	{
		scanf("%d",&x);
		ans=ans*C(n,x)%mod;
		n-=x;
	}
	printf("%d\n",ans);
	return 0;
}

