#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct node{int x,y,v;};
int n,m,k;
set<int> x[1010],y[1010];
char mp[1010][1010];
void del_node(int a,int b)
{
	x[a].erase(b);
	y[b].erase(a);
}
int bfs(int a,int b,int c,int d)
{
	vector<node> del;
	queue<node> q;
	q.push({a,b,0});
	del_node(a,b);
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(t.x==c&&t.y==d) return t.v;
		del.clear();
		auto it=x[t.x].lower_bound(t.y);
		
		while(*it-t.y<=k)
		{
			if(mp[t.x][*it]=='#') break;
			q.push({t.x,*it,t.v+1});
			del.push_back({t.x,*it,t.v+1});
			it++;
		}
		it=x[t.x].lower_bound(t.y);
		it--;
		while(t.y-(*it)<=k)
		{
			if(mp[t.x][*it]=='#') break;
			q.push({t.x,*it,t.v+1});
			del.push_back({t.x,*it,t.v+1});
			it--;
		}
		it=y[t.y].lower_bound(t.x);
		while(*it-t.x<=k)
		{
			if(mp[*it][t.y]=='#') break;
			q.push({*it,t.y,t.v+1});
			del.push_back({*it,t.y,t.v+1});
			it++;
		}
		it=y[t.y].lower_bound(t.x);
		it--;
		while(t.x-(*it)<=k)
		{
			if(mp[*it][t.y]=='#') break;
			q.push({*it,t.y,t.v+1});
			del.push_back({*it,t.y,t.v+1});
			it--;
		}
		for(auto &nd:del) del_node(nd.x,nd.y);
	}
	return -1;
}
int main()
{
	int i,j,a,b,c,d;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(i=1;i<=n;i++)
	{
		x[i].clear();
		x[i].insert(-INF);
		x[i].insert(INF);
	}
	for(i=1;i<=m;i++)
	{
		y[i].clear();
		y[i].insert(-INF);
		y[i].insert(INF);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			x[i].insert(j);
			y[j].insert(i);
		}
	}
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",bfs(a,b,c,d));
	return 0;
}
