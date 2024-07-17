#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e3+10;
int a[MAX],c[MAX];
struct node{int a,pos;};
vector<node> res[MAX];
ll dp1[2][MAX][2],dp2[2][MAX];
int main()
{
	int n,m,k,x,i,j,l,f;
	ll ans;
	scanf("%d%d%d%d",&n,&m,&k,&x);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=1;i<=k;i++) res[i].clear();
	for(i=1;i<=n;i++) res[c[i]].push_back({a[i],i});
	f=0;
	memset(dp2,0x3f,sizeof dp2);
	dp2[f][0]=0;
	for(i=1;i<=k;i++)
	{
		if(res[i].size()<=1) continue;
		memset(dp1,0x3f,sizeof dp1);
		dp1[0][0][0]=dp1[1][0][0]=0;
		for(j=1;j<=res[i].size();j++)
		{
			for(l=1;l<=res[i].size();l++)
			{
				dp1[j&1][l][0]=min(dp1[(j-1)&1][l][0],
					dp1[(j-1)&1][l-1][1]+res[i][j-1].a+x*res[i][j-1].pos);
				dp1[j&1][l][1]=min(dp1[(j-1)&1][l][1],
					dp1[(j-1)&1][l-1][0]+res[i][j-1].a-x*res[i][j-1].pos);
			}
		}
		f^=1;
		memset(dp2[f],0x3f,sizeof dp2[f]);
		for(j=0;j<=res[i].size();j+=2)
		{
			for(l=j;l<=n;l+=2)
			{
				dp2[f][l]=min(dp2[f][l],dp2[!f][l-j]+dp1[res[i].size()&1][j][0]);
			}
		}
	}
	ans=LLINF;
	for(i=0;i<=m;i++)
	{
		ans=min(ans,dp2[f][n-i]);
//		printf("%d %lld\n",n-i,dp2[f][n-i]);
	}
	if(ans==LLINF) puts("Impossible");
	else printf("%lld\n",ans);
	return 0;
}
/*
9 4 1 1
1 1 100 1 1 100 1 1 1
1 1 1 1 1 1 1 1 1

4 2 1 1
1 100 100 1
1 1 1 1
*/
