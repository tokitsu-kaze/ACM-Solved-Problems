#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX],vis[MAX];
int main()
{
	int T,n,i,j,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) vis[i]=0;
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			for(j=i;j<=n;j*=2)
			{
				if(vis[j]) continue;
				p[++tot]=j;
				vis[j]=1;
			}
		}
		printf("%d\n",2);
		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	}
	return 0;
}
