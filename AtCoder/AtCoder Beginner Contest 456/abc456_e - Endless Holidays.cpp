#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> mp[MAX*10],revmp[MAX*10];
int a[MAX],b[MAX],id[MAX][12],vis[MAX*10];
char s[MAX][12];
int in[MAX*10],tag[MAX*10],no_circle[MAX*10];
void topsort(int n)
{
	int i;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		no_circle[x]=1;
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
}
void bfs(int n)
{
	int i,x;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(no_circle[i]) continue;
		q.push(i);
		vis[i]=1;
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		tag[x]=1;
		for(auto &to:revmp[x])
		{
			if(!vis[to]) q.push(to);
		}
	}
}
int main()
{
	int T,n,m,i,j,tot,w,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
		scanf("%d",&w);
		for(i=1;i<=n;i++) scanf("%s",s[i]);
		tot=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<w;j++)
			{
				id[i][j]=++tot;
				mp[tot].clear();
				revmp[tot].clear();
				vis[tot]=no_circle[tot]=tag[tot]=in[tot]=0;
			}
		}
		for(i=1;i<=m;i++)
		{
			for(j=0;j<w;j++)
			{
				if(s[a[i]][j]=='o' && s[b[i]][(j+1)%w]=='o')
				{
					mp[id[a[i]][j]].push_back(id[b[i]][(j+1)%w]);
					revmp[id[b[i]][(j+1)%w]].push_back(id[a[i]][j]);
					in[id[b[i]][(j+1)%w]]++;
				}
				if(s[b[i]][j]=='o' && s[a[i]][(j+1)%w]=='o')
				{
					mp[id[b[i]][j]].push_back(id[a[i]][(j+1)%w]);
					revmp[id[a[i]][(j+1)%w]].push_back(id[b[i]][j]);
					in[id[a[i]][(j+1)%w]]++;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<w;j++)
			{
				if(s[i][j]=='o' && s[i][(j+1)%w]=='o')
				{
					mp[id[i][j]].push_back(id[i][(j+1)%w]);
					revmp[id[i][(j+1)%w]].push_back(id[i][j]);
					in[id[i][(j+1)%w]]++;
				}
			}
		}
		topsort(n*w);
		bfs(n*w);
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(s[i][0]=='x') continue;
			if(tag[id[i][0]]) ok=1;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
