#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int main()
{
	int n,a,b,i,k[205],dis[205],x,y;
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;i++) scanf("%d",&k[i]);
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	q.push(a);
	dis[a]=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		y=x-k[x];
		if(y>=1&&dis[x]+1<dis[y])
		{
			dis[y]=dis[x]+1;
			q.push(y);
		}
		y=x+k[x];
		if(y<=n&&dis[x]+1<dis[y])
		{
			dis[y]=dis[x]+1;
			q.push(y);
		}
	}
	if(dis[b]==INF) puts("-1");
	else printf("%d\n",dis[b]);
	return 0;
}
