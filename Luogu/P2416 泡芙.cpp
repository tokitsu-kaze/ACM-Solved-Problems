#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct LCA
{
	#define type int
	static const int N=MAX;
	static const int LOGN=log2(N)+3;
	static const type inf=INF;
	struct node{int to;type w;};
	struct info_node{int fa;type mn;}info[N][LOGN];
	int dep[N],limt,bin[LOGN],n;
	type dis[N];
	bool vis[N];
	vector<node> mp[N];
	void init(int _n)
	{
		int i;
		n=_n;
		for(i=0;i<=n;i++) mp[i].clear();
		for(limt=1;(1<<(limt-1))<n;limt++);
		for(i=bin[0]=1;i<=limt;i++) bin[i]=(bin[i-1]<<1);
	}
	void add_edge(int a,int b,type w=1){mp[a].push_back({b,w});}
	void dfs(int x,int pre)
	{
		int i,tmp;
		vis[x]=1;
		for(i=1;bin[i]<=dep[x];i++)
		{
			tmp=info[x][i-1].fa;
			info[x][i].fa=info[tmp][i-1].fa;
			info[x][i].mn=min(info[tmp][i-1].mn,info[x][i-1].mn);
		}
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==pre) continue;
			dis[to]=dis[x]+it.w;
			dep[to]=dep[x]+1;
			info[to][0]={x,it.w};
			dfs(to,x);
		}
	}
	void work(int rt=-1)
	{
		int i,j;
		for(i=0;i<=n;i++)
		{
			dep[i]=dis[i]=vis[i]=0;
			for(j=0;j<=limt;j++)
			{
				info[i][j]={0,inf};
			}
		}
		if(rt==-1)
		{
			for(i=1;i<=n;i++)
			{
				if(vis[i]) continue;
				dfs(i,-1);
			}
		}
		else dfs(rt,-1);
	}
	info_node go_info(int x,int d)
	{
		info_node res={x,inf};
		for(int i=0;i<=limt&&d;i++)
		{
			if(bin[i]&d)
			{
				d^=bin[i];
				res.mn=min(res.mn,info[x][i].mn);
				x=info[x][i].fa;
			}
		}
		res.fa=x;
		return res;
	}
	info_node lca_info(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		info_node res=go_info(x,dep[x]-dep[y]);
		x=res.fa;
		if(x==y) return res;
		for(int i=limt;~i;i--)
		{
			if(info[x][i].fa!=info[y][i].fa)
			{
				res.mn=min({res.mn,info[x][i].mn,info[y][i].mn});
				x=info[x][i].fa;
				y=info[y][i].fa;
			}
		}
		res.fa=info[x][0].fa;
		res.mn=min({res.mn,info[x][0].mn,info[y][0].mn});
		return res;
	}
	int go(int x,int d){return go_info(x,d).fa;}
	int lca(int x,int y){return lca_info(x,y).fa;}
	int get_len(int a,int b){return dep[a]+dep[b]-2*dep[lca(a,b)];}
	type get_path_min(int x,int y){return lca_info(x,y).mn;}
	type get_dis(int a,int b){return dis[a]+dis[b]-2*dis[lca(a,b)];}
	#undef type
}lca;
/*
O(nlogn)-O(logn)
 
lca.init(n);
lca.add_edge(a,b,w); // a->b
lca.work(rt);
*/
struct node{int x,w;};
struct Edge_Biconnected_Component
{
	int bcc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX];
	int st[MAX],top;
	vector<node> mp[MAX];
	vector<pair<int,int>> bridge;
	void dfs(int x,int fa)
	{
		int to,i,tmp,k;
		st[top++]=x;
		low[x]=dfn[x]=++tot;
		k=0;
		for(auto &it:mp[x])
		{
			to=it.x;
			if(to==fa&&!k) 
			{
				k++;
				continue;
			}
			if(!dfn[to])
			{
				dfs(to,x);
				low[x]=min(low[x],low[to]);
				if(low[to]>dfn[x]) bridge.push_back({x,to});
			}
			else low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			bcc_cnt++;
			do
			{
				tmp=st[--top];
				col[tmp]=bcc_cnt;
			}while(tmp!=x);
		}
	}
	void work(int n,vector<node> *_mp)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			low[i]=dfn[i]=0;
			mp[i]=_mp[i];
		}
		bcc_cnt=top=tot=0;
		bridge.clear();
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
	}
	int w[MAX];
	void rebuild(int n)
	{
		int i,to;
		for(i=1;i<=n;i++) w[i]=0;
		for(i=1;i<=n;i++)
		{
			for(auto &it:mp[i])
			{
				to=it.x;
				if(col[i]==col[to]) w[col[i]]|=it.w;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(auto &it:mp[i])
			{
				to=it.x;
				if(col[i]==col[to]) continue;
				lca.add_edge(col[i],col[to],it.w|w[col[i]]|w[col[to]]);
			}
		}
	}
}bcc;
/*
bcc.work(n,mp);
*/
vector<node> mp[MAX];
int main()
{
	int n,m,a,b,c,q,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	bcc.work(n,mp);
	lca.init(bcc.bcc_cnt);
	bcc.rebuild(n);
	lca.work(1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		a=bcc.col[a];
		b=bcc.col[b];
		if(lca.get_dis(a,b)||bcc.w[a]||bcc.w[b]) puts("YES");
		else puts("NO");
	}
	return 0;
}
