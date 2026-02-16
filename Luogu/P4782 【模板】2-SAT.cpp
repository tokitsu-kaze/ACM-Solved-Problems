#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
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
			if(!dfn[to])
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
	bool work(int *res)
	{
		int i;
		scc.work(2*n,mp);
		for(i=1;i<=n;i++)
		{
			if(scc.col[i]==scc.col[i+n]) return 0; // no solution
			if(scc.col[i]<scc.col[i+n]) res[i]=1;
			else res[i]=0;
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
int res[MAX];
int main()
{
	int n,m,i,a,fa,b,fb;
	scanf("%d%d",&n,&m);
	sat.init(n);
	while(m--)
	{
		scanf("%d%d%d%d",&a,&fa,&b,&fb);
		if(fa && fb)
		{
			sat.add_edge(a+n,b);
			sat.add_edge(b+n,a);
		}
		else if(fa && !fb)
		{
			sat.add_edge(a+n,b+n);
			sat.add_edge(b,a);
		}
		else if(!fa && fb)
		{
			sat.add_edge(a,b);
			sat.add_edge(b+n,a+n);
		}
		else if(!fa && !fb)
		{
			sat.add_edge(a,b+n);
			sat.add_edge(b,a+n);
		}
	}
	if(sat.work(res))
	{
		puts("POSSIBLE");
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	else puts("IMPOSSIBLE");
	return 0;
}
