#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],vis[MAX];
int main()
{
	int T,n,m,q,i,j,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(i=1;i<=n;i++) vis[i]=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) scanf("%d",&b[i]);
		ok=1;
		for(i=1,j=1;j<=m;j++)
		{
			if(i==n+1) continue;
			if(b[j]!=a[i])
			{
				if(vis[b[j]]) continue;
				if(!vis[a[i]])
				{
					ok=0;
					break;
				}
				i++;
				if(i<=n && b[j]!=a[i])
				{
					ok=0;
					break;
				}
				else
				{
					if(i<=n) vis[a[i]]=1;
				}
			}
			else vis[a[i]]=1;
		}
		if(ok) puts("YA");
		else puts("TIDAK");
	}
	return 0;
}


