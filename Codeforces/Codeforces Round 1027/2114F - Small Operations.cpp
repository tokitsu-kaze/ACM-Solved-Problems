#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
vector<int> fac[MAX];
void init_fac(int n)
{
	int i,j;
	for(i=1;i<=n;i++) fac[i].clear();
	for(i=2;i<=n;i++)
	{
		for(j=i;j<=n;j+=i) fac[j].push_back(i);
	}
}
int dis[MAX];
int bfs(int x,int y,int k)
{
	int i,t;
	for(i=1;i<=y;i++) dis[i]=INF;
	dis[y]=0;
	queue<int> q;
	q.push(y);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t==x) return dis[t];
		for(auto &it:fac[t])
		{
			if(it>k) break;
			if(dis[t/it]>dis[t]+1)
			{
				dis[t/it]=dis[t]+1;
				q.push(t/it);
			}
		}
	}
	return INF;
}
int main()
{
	int T,x,y,k,g,ans;
	init_fac(MAX-10);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&x,&y,&k);
		if(x>y) swap(x,y);
		g=__gcd(x,y);
		x/=g;
		y/=g;
		if(x==1) ans=bfs(1,y,k);
		else ans=bfs(1,x,k)+bfs(1,y,k);
		if(ans>=INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
