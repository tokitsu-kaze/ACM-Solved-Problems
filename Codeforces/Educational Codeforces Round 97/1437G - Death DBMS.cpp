#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct AC_Automaton
{
	static const int K=26;
	int nex[MAX][K],fail[MAX],cnt[MAX],lst[MAX];
	int root,tot,pos[MAX];
	int getid(char c){return c-'a';}//may need change
	int newnode()
	{
		tot;
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0;
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s,int n,int x) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
		}
		cnt[now]++;
		pos[x]=now;
	}
	void work()
	{
		int i,now;
		queue<int> q;
		for(i=0;i<K;i++)
		{
			if(nex[root][i]) q.push(nex[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			
			//suffix link
			if(cnt[fail[now]]) lst[now]=fail[now];
			else lst[now]=lst[fail[now]];
			
			for(i=0;i<K;i++)
			{
				if(nex[now][i])
				{
					fail[nex[now][i]]=nex[fail[now]][i];
					q.push(nex[now][i]);
				}
				else nex[now][i]=nex[fail[now]][i];
			}
		}
	}
	void build_fail_tree(vector<int> mp[])
	{
		// root is 0
		for(int i=0;i<tot;i++) mp[i].clear();
		for(int i=1;i<tot;i++) mp[fail[i]].push_back(i);
	}
}ac;
/*
i is the suffix for each node in the subtree(i) of the fail tree

ac.init();
ac.insert(s,len,id); s[0..len-1], id:1..n
ac.work();
ac.query(s,len); s[0..len-1]
ac.build_fail_tree(mp);
*/
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	multiset<int> s[MAX<<2];
	struct node
	{
		type v;
		void init(){v=-1;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=max(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		s[id].clear();
		if(l==r)
		{
			t[id].v=-1;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			if(qop==-1) s[id].erase(s[id].find(qv));
			else s[id].insert(qv);
			if(s[id].size()) t[id].v=*s[id].rbegin();
			else t[id].v=-1;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge_node(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v,int op)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qop=op;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.v;
		ql=l;
		qr=r;
		return query(1,n,1).v;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
struct Heavy_Light_Decomposition
{
	#define type int
	struct edge{int a,b;type v;};
	vector<int> mp[MAX];
	vector<edge> e;
	int dep[MAX],fa[MAX],sz[MAX],son[MAX];
	int id[MAX],top[MAX],dfn[MAX],tot;
	int n,rt;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		e.clear();
		e.push_back({0,0,0});
	}
	void add_edge(int a,int b,type v=0)
	{
		e.push_back({a,b,v});
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	void dfs1(int x,int pre,int h)
	{
		int i,to;
		dep[x]=h;
		fa[x]=pre;
		sz[x]=1;
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to==pre) continue;
			dfs1(to,x,h+1);
			sz[x]+=sz[to];
			if(son[x]==-1||sz[to]>sz[son[x]]) son[x]=to;
		}
	}
	void dfs2(int x,int tp)
	{
		int i,to;
		dfn[x]=++tot;
		id[dfn[x]]=x;
		top[x]=tp;
		if(son[x]==-1) return;
		dfs2(son[x],tp);
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
		}
	}
	void work(int _rt)
	{
		rt=_rt;
		for(int i=0;i<=n;i++) son[i]=-1;
		tot=0;
		dfs1(rt,0,0);
		dfs2(rt,rt);
	}
	int lca(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    return x;
	}
	int find_yson_toward_x(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(fa[top[x]]==y) return top[x];
			x=fa[top[x]];
		}
	    return son[y];
	}
	//node
	void init_node()
	{
		tr.build(n);
	}
	void upd_node(int x,int y,type v,int op)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			tr.upd(dfn[top[x]],dfn[x],v,op);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    tr.upd(dfn[x],dfn[y],v,op);
	}
	type ask_node(int x,int y)
	{
		type res=-1;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res=max(res,tr.ask(dfn[top[x]],dfn[x]));
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    res=max(res,tr.ask(dfn[x],dfn[y]));
	    return res;
	}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(rt);
hld.lca(a,b);
*/
char s[MAX];
vector<int> mp[MAX];
int v[MAX];
int main()
{
	int n,q,i,op,x,y,len,now,ans;
	scanf("%d%d",&n,&q);
	ac.init();
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ac.insert(s,strlen(s),i);
		v[i]=0;
	}
	ac.work();
	ac.build_fail_tree(mp);
	hld.init(ac.tot);
	for(i=0;i<ac.tot;i++)
	{
		for(auto &to:mp[i]) hld.add_edge(i,to);
	}
	hld.work(ac.root);
	hld.init_node();
	for(i=1;i<=n;i++) hld.upd_node(ac.pos[i],ac.pos[i],v[i],1);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			hld.upd_node(ac.pos[x],ac.pos[x],v[x],-1);
			v[x]=y;
			hld.upd_node(ac.pos[x],ac.pos[x],v[x],1);
		}
		else
		{
			scanf("%s",s);
			len=strlen(s);
			now=ac.root;
			ans=-1;
			for(i=0;i<len;i++)
			{
				now=ac.nex[now][s[i]-'a'];
				if(now==ac.root) continue;
				ans=max(ans,hld.ask_node(ac.root,now));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
