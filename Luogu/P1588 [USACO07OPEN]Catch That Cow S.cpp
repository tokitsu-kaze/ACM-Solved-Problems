#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int dis[MAX];
int main()
{
	int t,x,y,now,nex;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		memset(dis,0x3f,sizeof dis);
		queue<int> q;
		dis[x]=0;
		q.push(x);
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			if(now>=y)
			{
				dis[y]=min(dis[y],dis[now]+now-y);
				continue;
			}
			
			nex=2*now;
			if(dis[nex]>dis[now]+1)
			{
				dis[nex]=dis[now]+1;
				q.push(nex);
			}
			
			nex=now+1;
			if(dis[nex]>dis[now]+1)
			{
				dis[nex]=dis[now]+1;
				q.push(nex);
			}
			
			nex=now-1;
			if(dis[nex]>dis[now]+1)
			{
				dis[nex]=dis[now]+1;
				q.push(nex);
			}
		}
		printf("%d\n",dis[y]);
	}
	return 0;
}
