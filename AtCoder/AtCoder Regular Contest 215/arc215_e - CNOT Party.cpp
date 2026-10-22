#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int to,id;};
struct Strongly_Connected_Components
{
	int scc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX],sz[MAX];
	int st[MAX],top,flag[MAX];
	vector<node> mp[MAX];
	void dfs(int x)
	{
		int tmp;
		st[top++]=x;
		flag[x]=1;
		low[x]=dfn[x]=++tot;
		for(auto &it:mp[x])
		{
			int to=it.to;
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
	void work(int n,vector<node> *_mp)
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
char sa[MAX],sb[MAX];
vector<node> mp[MAX];
vector<int> ans,colmp[MAX];
int n,m,self_loop[MAX],vis[MAX],in[MAX];
void bfs()
{
	int i,x;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(sa[i]=='1')
		{
			q.push(i);
			vis[i]=1;
		}
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto &it:mp[x])
		{
			if(sa[it.to]=='0')
			{
				sa[it.to]='1';
				ans.push_back(it.id);
			}
			if(!vis[it.to])
			{
				q.push(it.to);
				vis[it.to]=1;
			}
		}
	}
}
void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	for(auto &it:mp[x])
	{
		if(vis[it.to]) continue;
		dfs(it.to);
		if(sa[x]=='0') continue;
		if(sa[it.to]=='1' && sb[it.to]=='0')
		{
			sa[it.to]='0';
			ans.push_back(it.id);
		}
	}
}
int main()
{
	int T,i,a,b,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",sa+1);
		scanf("%s",sb+1);
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			colmp[i].clear();
			self_loop[i]=0;
			vis[i]=in[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			if(a==b) self_loop[a]=i;
			else mp[a].push_back({b,i});
		}
		ans.clear();
		bfs();
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(sb[i]=='1' && sa[i]=='0') ok=0;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		
		scc.work(n,mp);
		for(i=1;i<=n;i++)
		{
			if(sa[i]=='0') continue;
			for(auto &it:mp[i])
			{
				if(scc.col[i]!=scc.col[it.to])
				{
					in[scc.col[it.to]]++;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			colmp[scc.col[i]].push_back(i);
			vis[i]=0;
		}
		for(i=1;i<=scc.scc_cnt;i++)
		{
			if(in[i]) continue;
			for(auto &x:colmp[i])
			{
				if(sa[x]=='0') continue;
				if(sb[x]=='1' || self_loop[x])
				{
					dfs(x);
					if(sb[x]=='0' && self_loop[x])
					{
						assert(sa[x]=='1');
						ans.push_back(self_loop[x]);
						sa[x]='0';
					}
					break;
				}
			}
		}
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(sa[i]!=sb[i]) ok=0;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		printf("%d\n",(int)ans.size());
		for(i=0;i<ans.size();i++) printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
	}
	return 0;
}

/*
先bfs全翻成 1，判一下不合法。
然后按照dfs树自底向上操作即可。
然后发现根要么满足b=1，要么有自环。
scc缩点后，在入度为0的scc里找根，
找到根后在原图上dfs即可。
注意统计入度时，需要无视不能操作的点。
*/
