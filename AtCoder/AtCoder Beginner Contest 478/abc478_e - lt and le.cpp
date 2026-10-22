#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Strongly_Connected_Components
{
	int scc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX],sz[MAX];
	int st[MAX],top,flag[MAX];
	vector<int> mp[MAX];
	void dfs(int x)
	{
		int tmp;
		st[top++]=x;
		flag[x]=1;
		low[x]=dfn[x]=++tot;
		for(auto &to:mp[x])
		{
			if(!dfn[to]) // dfn must be cleared
			{
				dfs(to);
				low[x]=min(low[x],low[to]);
			}
			else if(flag[to]) low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			scc_cnt++;
			do
			{
				tmp=st[--top];
				flag[tmp]=0;
				col[tmp]=scc_cnt;
				sz[scc_cnt]++;
			}while(tmp!=x);
		}
	}
	void work(int n,vector<int> *_mp)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			col[i]=sz[i]=flag[i]=dfn[i]=0;
			mp[i].assign(_mp[i].begin(),_mp[i].end());
		}
		scc_cnt=top=tot=0;
		for(i=1;i<=n;i++)
		{
			if(col[i]) continue;
			dfs(i);
		}
	}
}scc;
/*
scc.work(n,mp);
*/
struct node{int to,f;};
int ans[MAX];
void topsort(int n,vector<node> mp[],int *in)
{
	int i,x,to;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i])
		{
			q.push(i);
			ans[i]=1;
		}
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto &it:mp[x])
		{
			to=it.to;
			if(it.f) ans[to]=max(ans[to],ans[x]+1);
			else ans[to]=max(ans[to],ans[x]);
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
}
int in[MAX],op[MAX],a[MAX],b[MAX];
vector<int> mp[MAX];
vector<node> g[MAX];
int main()
{
	int n,q,i,ok;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		g[i].clear();
		in[i]=0;
		ans[i]=-1;
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",&op[i],&a[i],&b[i]);
		mp[a[i]].push_back(b[i]);
	}
	scc.work(n,mp);
	ok=1;
	for(i=1;i<=q;i++)
	{
		if(scc.col[a[i]]==scc.col[b[i]])
		{
			if(op[i]==1) ok=0;
			continue;
		}
		g[scc.col[a[i]]].push_back({scc.col[b[i]],op[i]});
		in[scc.col[b[i]]]++;
	}
	topsort(scc.scc_cnt,g,in);
	for(i=1;i<=scc.scc_cnt;i++)
	{
		if(ans[i]>n) ok=0;
	}
	if(ok)
	{
		puts("Yes");
		for(i=1;i<=n;i++) printf("%d%c",ans[scc.col[i]]," \n"[i==n]);
	}
	else puts("No");
	return 0;
}
