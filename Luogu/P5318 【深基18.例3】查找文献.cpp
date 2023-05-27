#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
vector<int> mp[MAX];
vector<int> ra,rb;
int flag[MAX];
void dfs(int x)
{
	if(flag[x]) return;
	flag[x]=1;
	ra.push_back(x);
	for(auto &to:mp[x]) dfs(to);
}
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	flag[x]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		rb.push_back(x);
		for(auto &to:mp[x])
		{
			if(flag[to]) continue;
			q.push(to);
			flag[to]=1;
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
	}
	for(i=1;i<=n;i++) sort(mp[i].begin(),mp[i].end());
	ra.clear();
	memset(flag,0,sizeof flag);
	dfs(1);
	rb.clear();
	memset(flag,0,sizeof flag);
	bfs(1);
	for(i=0;i<ra.size();i++) printf("%d%c",ra[i]," \n"[i==ra.size()-1]);
	for(i=0;i<rb.size();i++) printf("%d%c",rb[i]," \n"[i==rb.size()-1]);
	return 0;
}
