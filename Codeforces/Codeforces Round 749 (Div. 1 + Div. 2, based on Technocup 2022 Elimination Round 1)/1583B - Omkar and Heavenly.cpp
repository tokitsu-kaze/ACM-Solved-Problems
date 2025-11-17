#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int vis[MAX];
int main()
{
	int T,n,m,i,a,b,c,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) vis[i]=0;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			vis[b]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(!vis[i]) x=i;
		}
		for(i=1;i<=n;i++)
		{
			if(x==i) continue;
			printf("%d %d\n",x,i);
		}
	}
	return 0;
}
