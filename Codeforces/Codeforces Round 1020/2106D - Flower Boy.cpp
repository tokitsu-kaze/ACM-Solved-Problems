#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],pre[MAX],suf[MAX];
int main()
{
	int T,n,m,i,j,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) scanf("%d",&b[i]);
		pre[0]=0;
		for(i=1,j=0;i<=n;i++)
		{
			pre[i]=pre[i-1];
			if(j+1<=m && a[i]>=b[j+1]) pre[i]=++j;
		}
		suf[n+1]=m+1;
		for(i=n,j=m+1;i;i--)
		{
			suf[i]=suf[i+1];
			if(j-1>=1 && a[i]>=b[j-1]) suf[i]=--j;
		}
		ans=INF;
		for(i=0;i<=n;i++)
		{
			if(pre[i]+1>=suf[i+1]) ans=0;
			else if(pre[i]+2==suf[i+1]) ans=min(ans,b[pre[i]+1]);
		}
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
