#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;

int GetMove();
void MakeMove(int v);

int dep[MAX],tag[MAX],vis[MAX],fa[MAX],match[MAX],ret_id[MAX];
vector<int> mp[MAX];
vector<int> path[MAX];
void dfs(int x)
{
	int id;
	vis[x]=1;
	id=0;
	for(auto &to:mp[x])
	{
		if(vis[to]) continue;
		fa[to]=x;
		dep[to]=dep[x]+1;
		dfs(to);
		if(x!=1 && ret_id[to])
		{
			if(id)
			{
				match[id]=ret_id[to];
				match[ret_id[to]]=id;
				id=0;
			}
			else id=ret_id[to];
		}
	}
	if(tag[x])
	{
		if(id)
		{
			match[x]=id;
			match[id]=x;
			id=0;
		}
		else id=x;
	}
	ret_id[x]=id;
}
void SocialEngineering(int n,int m,vector<pair<int,int>> edges)
{
	int i,a,b,x;
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		path[i].clear();
		dep[i]=tag[i]=vis[i]=fa[i]=match[i]=ret_id[i]=0;
	}
	for(i=0;i<m;i++)
	{
		a=edges[i].first;
		b=edges[i].second;
		mp[a].push_back(b);
		mp[b].push_back(a);
		if(a==1) tag[b]=1;
		else if(b==1) tag[a]=1;
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		if(!tag[i]) continue;
		if(!match[i]) return;
		
		vector<int> ra,rb;
		a=i;
		b=match[i];
		while(dep[a]>dep[b])
		{
			if(a!=i) ra.push_back(a);
			a=fa[a];
		}
		while(dep[b]>dep[a])
		{
			rb.push_back(b);
			b=fa[b];
		}
		while(a!=b)
		{
			if(a!=i) ra.push_back(a);
			rb.push_back(b);
			a=fa[a];
			b=fa[b];
		}
		if(a!=i) ra.push_back(a);
		
		for(auto &it:ra) path[i].push_back(it);
		reverse(rb.begin(),rb.end());
		rb.push_back(1);
		for(auto &it:rb) path[i].push_back(it);
	}
	while(1)
	{
		x=GetMove();
		if(!x) return;
		for(auto &to:path[x]) MakeMove(to);
	}
}
/*
就是跟 1 直接相邻的点，两两配对，并且路径不相交。问是否配对。
发现直接dfs的话，如果连通着的是偶数个是一定能配对的，画画图就知道了。
所以先把匹配找出来，暴力预处理出配对的路径，然后按题意模拟即可。
*/
