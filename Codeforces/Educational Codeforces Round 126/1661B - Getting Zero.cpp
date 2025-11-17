#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=32768;
int a[MAX],dis[mod];
void bfs()
{
	int t,nex;
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	q.push(0);
	dis[0]=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		
		nex=(t-1+mod)%mod;
		if(dis[nex]>dis[t]+1)
		{
			dis[nex]=dis[t]+1;
			q.push(nex);
		}
		
		if(t%2==0)
		{
			nex=t/2;
			if(dis[nex]>dis[t]+1)
			{
				dis[nex]=dis[t]+1;
				q.push(nex);
			}
		}
		
		if((t+mod)%2==0)
		{
			nex=(t+mod)/2;
			if(nex<mod && dis[nex]>dis[t]+1)
			{
				dis[nex]=dis[t]+1;
				q.push(nex);
			}
		}
	}
}
int main()
{
	int T,n,i,x;
	bfs();
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) printf("%d%c",dis[a[i]]," \n"[i==n]);
	return 0;
}
