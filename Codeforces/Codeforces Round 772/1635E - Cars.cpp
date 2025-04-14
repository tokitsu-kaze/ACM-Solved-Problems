#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int tp[MAX],x[MAX],y[MAX],col[MAX],ok;
int in[MAX];
void dfs(int x,int fa,int c)
{
	if(col[x]!=-1) return;
	col[x]=c;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		if(col[to]!=-1)
		{
			if(col[to]==c) ok=0;
			continue;
		}
		dfs(to,x,c^1);
	}
}
int ans[MAX];
int topsort(int n,vector<int> mp[],int *in)
{
	int i,x,tot;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	tot=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		ans[x]=++tot;
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
	if(tot!=n) return -1;
	return 0;
}
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		col[i]=-1;
		in[i]=ans[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&tp[i],&x[i],&y[i]);
		mp[x[i]].push_back(y[i]);
		mp[y[i]].push_back(x[i]);
	}
	ok=1;
	for(i=1;i<=n;i++) dfs(i,0,0);
	if(!ok) return 0*puts("NO");
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=m;i++)
	{
		if(tp[i]==1)// <-  ->
		{
			if(col[x[i]]==0) // dir left
			{
				mp[x[i]].push_back(y[i]);
				in[y[i]]++;
			}
			else // dir right
			{
				mp[y[i]].push_back(x[i]);
				in[x[i]]++;
			}
		}
		else // ->  <-
		{
			if(col[x[i]]==0) // dir left
			{
				mp[y[i]].push_back(x[i]);
				in[x[i]]++;
			}
			else // dir right
			{
				mp[x[i]].push_back(y[i]);
				in[y[i]]++;
			}
		}
	}
	if(topsort(n,mp,in)==-1) return 0*puts("NO");
	puts("YES");
	for(i=1;i<=n;i++)
	{
		if(col[i]==0) printf("L %d\n",ans[i]);
		else printf("R %d\n",ans[i]);
	}
	return 0;
}
