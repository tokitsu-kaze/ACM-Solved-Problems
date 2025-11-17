#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,c,now,x,mn,vis[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&c);
		memset(vis,0,sizeof vis);
		mn=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			vis[x]=1;
			mn=min(mn,x);
		}
		now=c;
		if(now<=mn) now=mn+1;
		while(vis[now]) now++;
		printf("%d\n",now-c);
	}
	return 0;
}
