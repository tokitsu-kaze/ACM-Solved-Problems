#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int p[MAX],vis[MAX];
int main()
{
	int T,n,i,ans,cnt,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			vis[i]=0;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			x=i;
			cnt=0;
			while(!vis[x])
			{
				vis[x]=1;
				cnt++;
				x=p[x];
			}
			ans+=(cnt-1)/2;
		}
		printf("%d\n",ans);
	}
	return 0;
}

