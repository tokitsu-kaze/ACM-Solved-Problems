#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,m,i,x,nex;
	ll ans;
	scanf("%d%d",&n,&m);
	map<int,int> dis;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		dis[x]=0;
		q.push(x);
	}
	vector<int> res;
	ans=0;
	while(res.size()<m)
	{
		x=q.front();
		q.pop();
		if(dis[x])
		{
			ans+=dis[x];
			res.push_back(x);
		}
		for(i=-1;i<=1;i++)
		{
			if(i==0) continue;
			nex=x+i;
			if(dis.count(nex)) continue;
			dis[nex]=dis[x]+1;
			q.push(nex);
		}
	}
	printf("%lld\n",ans);
	for(i=0;i<m;i++) printf("%d%c",res[i]," \n"[i+1==m]);
	return 0;
}
