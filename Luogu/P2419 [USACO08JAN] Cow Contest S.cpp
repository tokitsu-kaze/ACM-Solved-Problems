#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int mp[105][105];
int main()
{
	int n,m,i,j,k,a,b,cnt,ans;
	scanf("%d%d",&n,&m);
	memset(mp,0,sizeof mp);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a][b]=1;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				mp[i][j]|=(mp[i][k]&mp[k][j]);
			}
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		cnt=0;
//		for(j=1;j<=n;j++) printf("%d%c",mp[i][j]||mp[j][i]," \n"[j==n]);
		for(j=1;j<=n;j++) cnt+=(mp[i][j]||mp[j][i]);
		if(cnt==n-1) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
