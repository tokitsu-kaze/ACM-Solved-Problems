#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int mp[805][805],res[2020],vis[2020];
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) scanf("%d",&mp[i][j]);
		}
		for(i=1;i<=n;i++) res[i+1]=mp[1][i];
		for(i=2;i<=n;i++) res[n+i]=mp[i][n];
		for(i=1;i<=2*n;i++) vis[i]=0;
		for(i=2;i<=2*n;i++) vis[res[i]]=1;
		for(i=1;i<=2*n;i++)
		{
			if(!vis[i])
			{
				res[1]=i;
				break;
			}
		}
		for(i=1;i<=2*n;i++) printf("%d%c",res[i]," \n"[i==2*n]);
	}
	return 0;
}
