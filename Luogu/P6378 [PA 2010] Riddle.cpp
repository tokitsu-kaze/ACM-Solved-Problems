#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e6+10;
struct Strongly_Connected_Components
{
	int scc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX],sz[MAX];
	int st[MAX],top,flag[MAX];
	vector<int> *mp;
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
		mp=_mp;
		for(i=1;i<=n;i++) col[i]=sz[i]=flag[i]=dfn[i]=0;
		scc_cnt=top=tot=0;
		for(i=1;i<=n;i++)
		{
			if(col[i]) continue;
			dfs(i);
		}
	}
	void rebuild(int n,vector<int> *g)
	{
		int i;
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=n;i++)
		{
			for(auto &to:mp[i])
			{
				if(col[i]==col[to]) continue;
				g[col[i]].push_back(col[to]);
			}
		}
	}
}scc;
/*
scc.work(n,mp);
*/
struct Tow_SAT
{
	static const int N=MAX;
	int n;
	vector<int> mp[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=2*n;i++) mp[i].clear();
	}
	void add_edge(int a,int b){mp[a].push_back(b);}
	bool work()
	{
		int i;
		scc.work(2*n,mp);
		for(i=1;i<=n;i++)
		{
			if(scc.col[i]==scc.col[i+n]) return 0; // no solution
		}
		return 1;
	}
}sat;
/*
MAX > 2*n
sat.init(n);
sat.work(int *res);

sat.add_edge(a,b); -> if a is true, b must true
special:
a must false -> if a is true, a must false
a must true  -> if a is false, a must true
*/
int x[MAX];
int id[MAX],pre[MAX];
int main()
{
	int n,m,k,i,tot,a,b,w;
	scanf("%d%d%d",&n,&m,&k);
	tot=0;
	for(i=1;i<=n;i++)
	{
		id[i]=++tot;
		pre[i]=++tot;
	}
	sat.init(tot);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		sat.add_edge(id[a]+tot,id[b]);
		sat.add_edge(id[b]+tot,id[a]);
	}
	while(k--)
	{
		scanf("%d",&w);
		for(i=1;i<=w;i++) scanf("%d",&x[i]);
		if(w==1)
		{
			sat.add_edge(id[x[1]]+tot,id[x[1]]);
			continue;
		}
		for(i=1;i<=w;i++)
		{
			sat.add_edge(id[x[i]],pre[x[i]]);
			sat.add_edge(pre[x[i]]+tot,id[x[i]]+tot);
			if(i-1>=1)
			{
				sat.add_edge(pre[x[i-1]],pre[x[i]]);
				sat.add_edge(pre[x[i]]+tot,pre[x[i-1]]+tot);
			}
		}
		for(i=2;i<=w;i++)
		{
			sat.add_edge(id[x[i]],pre[x[i-1]]+tot);
			sat.add_edge(pre[x[i-1]],id[x[i]]+tot);
		}
	}
	if(sat.work()) puts("TAK");
	else puts("NIE");
	return 0;
}
/*
新建一个节点 pre_a[i] 表示前缀是否选择
如果pre_a[i-1]选了或者a[i]选了,那么pre_a[i]必选
后缀同理。但发现其实不需要后缀。如果后面选了，那前面必不能选。 
*/
