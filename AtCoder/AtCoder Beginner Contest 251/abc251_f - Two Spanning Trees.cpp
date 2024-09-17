#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct node{int x,y;};
vector<node> t1,t2;
vector<int> mp[MAX];
bool vis[MAX];
void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	for(auto &to:mp[x])
	{
		if(vis[to]) continue;
		t1.push_back({x,to});
		dfs(to);
	}
}
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto &to:mp[x])
		{
			if(vis[to]) continue;
			t2.push_back({x,to});
			vis[to]=1;
			q.push(to);
		}
	}
}
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for(i=1;i<=n;i++) vis[i]=0;
	dfs(1);
	for(i=1;i<=n;i++) vis[i]=0;
	bfs(1);
	assert(t1.size()==n-1);
	assert(t2.size()==n-1);
	for(auto &it:t1) printf("%d %d\n",it.x,it.y);
	for(auto &it:t2) printf("%d %d\n",it.x,it.y);
	return 0;
}

