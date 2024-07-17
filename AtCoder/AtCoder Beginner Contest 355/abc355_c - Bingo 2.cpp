#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e6+10;
int x[MAX],y[MAX],cntx[MAX],cnty[MAX],cnt1,cnt2;
int main()
{
	int i,j,n,m,tot,ans,a;
	scanf("%d%d",&n,&m);
	tot=0;
	cnt1=cnt2=n;
	for(i=1;i<=n;i++)
	{
		cntx[i]=cnty[i]=n;
		for(j=1;j<=n;j++)
		{
			tot++;
			x[tot]=i;
			y[tot]=j;
		}
	}
	ans=-1;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a);
		if(ans!=-1) continue;
		cntx[x[a]]--;
		cnty[y[a]]--;
		if(!cntx[x[a]]||!cnty[y[a]]) ans=i;
		if(x[a]==y[a]) cnt1--;
		if(x[a]+y[a]==n+1) cnt2--;
		if(!cnt1||!cnt2) ans=i;
	}
	printf("%d\n",ans);
	return 0;
}

