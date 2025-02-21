#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll comb[27][27];
void init_comb(int n,int m)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=i;j++)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
		}
	}
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
ll res[27];
void gao(int x,int exp)
{
	int i,now;
	now=1;
	for(i=exp;i>=0;i--)
	{
		res[i]+=x*C(exp,i)*now;
		now*=-1;
	}
}
int main()
{
	int n,i,x;
	init_comb(25,25);
	scanf("%d",&n);
	memset(res,0,sizeof res);
	for(i=0;i<=n;i++)
	{
		scanf("%d",&x);
		if(i==n) res[n-i]+=x;
		else gao(x,n-i);
	}
	reverse(res,res+n+1);
	for(i=0;i<=n;i++) printf("%lld%c",res[i]," \n"[i==n]);
	return 0;
}

