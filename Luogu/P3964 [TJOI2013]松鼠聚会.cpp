#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int x[MAX],y[MAX];
int nx[MAX],ny[MAX];
ll bitx[MAX],bity[MAX];
int main()
{
	int n,i,px,py;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;i++)
	{
		nx[i]=x[i]+y[i];
		ny[i]=x[i]-y[i];
	}
	sort(nx+1,nx+1+n);
	sort(ny+1,ny+1+n);
	bitx[0]=bity[0]=0;
	for(i=1;i<=n;i++)
	{
		bitx[i]=bitx[i-1]+nx[i];
		bity[i]=bity[i-1]+ny[i];
	}
	ans=LLINF;
	for(i=1;i<=n;i++)
	{
		px=lower_bound(nx+1,nx+1+n,x[i]+y[i])-nx;
		py=lower_bound(ny+1,ny+1+n,x[i]-y[i])-ny;
		ans=min(ans,1LL*px*(x[i]+y[i])-bitx[px]+
					(bitx[n]-bitx[px])-1LL*(n-px)*(x[i]+y[i])+
					1LL*py*(x[i]-y[i])-bity[py]+
					(bity[n]-bity[py])-1LL*(n-py)*(x[i]-y[i]));
	}
	printf("%lld\n",ans/2);
	return 0;
}
