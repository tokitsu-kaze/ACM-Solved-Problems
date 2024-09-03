#include <bits/stdc++.h>
using namespace std;
const int MAX=2e3+10;
struct node{int p,c,x;}t[MAX];
int dpx[MAX][MAX],dpc[MAX][MAX];
int main()
{
	int n,a,b,i,j,ans,cost;
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;i++) scanf("%d%d%d",&t[i].p,&t[i].c,&t[i].x);
	sort(t+1,t+1+n,[&](node x,node y){
		return x.x<y.x;
	});
	memset(dpx,0,sizeof dpx);
	for(i=1;i<=n;i++)
	{
		for(j=b;j>=0;j--)
		{
			dpx[i][j]=dpx[i-1][j];
			cost=t[i].x*t[i].c;
			if(j>=cost) dpx[i][j]=max(dpx[i][j],dpx[i-1][j-cost]+t[i].p);
		}
	}
	memset(dpc,0,sizeof dpc);
	for(i=n;i;i--)
	{
		for(j=a;j>=0;j--)
		{
			dpc[i][j]=dpc[i+1][j];
			if(j>=t[i].c) dpc[i][j]=max(dpc[i][j],dpc[i+1][j-t[i].c]+t[i].p);
		}
	}
	ans=max(dpc[1][a],dpx[n][b]);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=min(t[i].c,a);j++)
		{
			cost=(t[i].c-j)*t[i].x;
			if(b-cost>=0) ans=max(ans,dpx[i-1][b-cost]+dpc[i+1][a-j]+t[i].p);
		}
	}
	printf("%d\n",ans);
	return 0;
}

