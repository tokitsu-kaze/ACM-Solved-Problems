#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int mp[MAX][MAX],mn[MAX][MAX],mx[MAX][MAX];
int main()
{
	int T,n,m,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
				mn[i][j]=INF;
				mx[i][j]=-INF;
			}
		}
		for(i=0;i<=n;i++)
		{
			mn[i][0]=INF;
			mx[i][0]=-INF;
		}
		for(j=0;j<=m;j++)
		{
			mn[0][j]=INF;
			mx[0][j]=-INF;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(i==1 && j==1)
				{
					mn[1][1]=mx[1][1]=mp[1][1];
					continue;
				}
				mn[i][j]=min(mn[i-1][j],mn[i][j-1])+mp[i][j];
				mx[i][j]=max(mx[i-1][j],mx[i][j-1])+mp[i][j];
			}
		}
		if(mn[n][m]<=0 && mx[n][m]>=0 && (n+m-1)%2==0) puts("YES");
		else puts("NO");
	}
	return 0;
}
