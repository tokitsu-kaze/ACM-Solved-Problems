#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int pre[MAX][MAX],suf[2][MAX],sufmn[MAX][MAX];
char s[MAX],t[MAX];
int main()
{
	int T,n,m,i,j,ans,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=m+1;j++)
			{
				pre[i][j]=sufmn[i][j]=INF;
			}
		}
		pre[0][0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				pre[i][j]=pre[i-1][j]+2;
				if(j>0 && s[i]==t[j])
				{
					pre[i][j]=min(pre[i][j],pre[i-1][j-1]+1);
				}
			}
		}
		f=0;
		for(j=m+1;~j;j--) suf[f][j]=INF;
		suf[f][m+1]=sufmn[n+1][m+1]=0;
		for(i=n;i;i--)
		{
			f^=1;
			for(j=m+1;~j;j--) suf[f][j]=INF;
			for(j=m+1;j;j--)
			{
				suf[f][j]=sufmn[i][j]=suf[!f][j]+1;
				if(j<=m && s[i]==t[j])
				{
					suf[f][j]=min(suf[f][j],suf[!f][j+1]+1);
					sufmn[i][j]=min(suf[f][j],sufmn[i+1][j+1]);
				}
			}
		}
		ans=min(pre[n][m],sufmn[1][1]);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				ans=min(ans,pre[i][j]+sufmn[i+1][j+1]);
			}
		}
		if(ans>=INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
