#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int w[105],vis[105];
int main()
{
	int x,n,q,p,i;
	scanf("%d%d",&x,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		vis[i]=0;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&p);
		if(vis[p]) x-=w[p];
		else x+=w[p];
		vis[p]^=1;
		printf("%d\n",x);
	}
	return 0;
}
