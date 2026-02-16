#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=900+10;
const int mod=1e9+7;
int comb[MAX][MAX];
void init_comb(int n)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=i;j++)
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
int d,l;
ll cal(int x,int y)
{
	if(x<=0||y<=0) return 0;
	if(d+l>x*y) return 0;
	return C(x*y,d+l)*C(d+l,d)%mod;
}
int main()
{
	int n,m,x,y;
	ll ans;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&x,&y);
	scanf("%d%d",&d,&l);
	init_comb(n*m);
	ans=0;
	ans+=cal(x,y);
	ans-=cal(x-1,y)+cal(x,y-1)+cal(x-1,y)+cal(x,y-1);
	ans+=cal(x-1,y-1)+cal(x-1,y-1)+cal(x-1,y-1)
		+cal(x-1,y-1)+cal(x,y-2)+cal(x-2,y);
	ans-=cal(x-1,y-2)+cal(x-1,y-2)+cal(x-2,y-1)+cal(x-2,y-1);
	ans+=cal(x-2,y-2);
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans*(n-x+1)%mod*(m-y+1)%mod);
	return 0;
}
