#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int vis[MAX];
int main()
{
	int n,i,a,b,x,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		vis[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==0 && b==0) vis[i]=1;
		else
		{
			mp[a].push_back(i);
			mp[b].push_back(i);
		}
	}
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(vis[i]) q.push(i);
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto &to:mp[x])
		{
			if(vis[to]) continue;
			vis[to]=1;
			q.push(to);
		}
	}
	ans=0;
	for(i=1;i<=n;i++) ans+=vis[i];
	printf("%d\n",ans);
	return 0;
}
