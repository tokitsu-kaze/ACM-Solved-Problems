#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<20)+10;
int comb[25][25];
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
		}
	}
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
ll res[MAX],a[22],tot;
const ll limt=4e18;
void dfs(int x,int n,int now,ll fm)
{
	if(fm>tot) return;
	if(x==n)
	{
		res[now]=tot/fm;
		return;
	}
	dfs(x+1,n,now,fm);
	if(fm/__gcd(fm,a[x])<=limt/a[x])
	{
		dfs(x+1,n,now|(1<<x),fm/__gcd(fm,a[x])*a[x]);
	}
}
int main()
{
	init_comb(20,20);
	int n,m,i,pc;
	__int128_t ans;
	scanf("%d%d%lld",&n,&m,&tot);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	dfs(0,n,0,1);
	ans=0;
	for(i=0;i<(1<<n);i++)
	{
		pc=__builtin_popcount(i);
		if(pc<m) continue;
		if(pc==m) ans+=res[i];
		else 
		{
			if((pc-m+1)&1) ans+=C(pc,m)*res[i];
			else ans-=C(pc,m)*res[i];
		}
	}
	printf("%lld\n",(ll)ans);
	return 0;
}
