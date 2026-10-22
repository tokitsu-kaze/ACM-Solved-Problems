#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int a[MAX],b[MAX];
ll resx[MAX],resy[MAX],cntx[MAX],cnty[MAX],sum[MAX],cnt[MAX];
ll res[MAX][MAX];
int main()
{
	int n,m,i,j,x,y;
	ull ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	memset(cntx,0,sizeof cntx);
	memset(cnty,0,sizeof cnty);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			x=(i+j);
			y=(i-j+n);
			cntx[x]+=1LL*a[i]*b[j]%m;
			cnty[y]+=1LL*a[i]*b[j]%m;
		}
	}
	sum[0]=cnt[0]=0;
	for(i=1;i<=2*n;i++)
	{
		sum[i]=sum[i-1]+i*cntx[i];
		cnt[i]=cnt[i-1]+cntx[i];
	}
	for(i=1;i<=2*n;i++)
	{
		resx[i]=cnt[i]*i-sum[i];
		resx[i]+=(sum[2*n]-sum[i])-(cnt[2*n]-cnt[i])*i;
	}
	sum[0]=cnt[0]=0;
	for(i=1;i<=2*n;i++)
	{
		sum[i]=sum[i-1]+i*cnty[i];
		cnt[i]=cnt[i-1]+cnty[i];
	}
	for(i=1;i<=2*n;i++)
	{
		resy[i]=cnt[i]*i-sum[i];
		resy[i]+=(sum[2*n]-sum[i])-(cnt[2*n]-cnt[i])*i;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			x=i+j;
			y=i-j+n;
			ans^=(resx[x]+resy[y])/2+1ULL*(i-1)*n+(j-1);
//			printf("%lld%c",(resx[x]+resy[y])/2," \n"[j==n]);
		}
	}
	printf("%llu\n",ans);
	return 0;
}
