#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll comb[MAX][105];
void init_comb(int n,int m)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=min(i,m);j++)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
			if(comb[i][j]>1e8) comb[i][j]=1e9;
		}
	}
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
int res[105];
int main()
{
	int n,x,i,j,k,now,tot;
	init_comb(2e4,100);
	scanf("%d%d",&n,&x);
	if(x==1) return 0*printf("%d\n",n);
	for(i=2e4;i>=x;i--)
	{
		if(C(i,x)>n) continue;
		k=i;
		now=0;
		tot=0;
		for(j=x;j>=1;j--)
		{
			while(k>j && now+C(k,j)>n) k--;
			now+=C(k,j);
			res[++tot]=k;
			if(now>=n) break;
		}
		if(now==n)
		{
			for(j=1;j<=tot;j++) printf("%d%c",res[j]," \n"[i==tot]);
			break;
		}
	}
	return 0;
}
