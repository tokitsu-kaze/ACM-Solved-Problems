#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
ll bit[MAX],val[MAX];
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],tag[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		v[ls]+=tag[id]*(bit[mid]-bit[l-1]);
		v[rs]+=tag[id]*(bit[r]-bit[mid]);
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		v[id]=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			v[id]+=(bit[r]-bit[l-1])*qv;
			tag[id]+=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res+=v[id];
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		res=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr[2];
struct Heavy_Light_Decomposition
{
	#define type ll
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
	void init_node()
	{
		int i;
		for(i=1;i<=n;i++) bit[dfn[i]]=val[i];
		for(i=1;i<=n;i++) bit[i]+=bit[i-1];
		tr[0].build(n);
		tr[1].build(n);
	}
	void modify_node(int x,int y,type val,int f)
	{  
		while(top[x]!=top[y])
		{  
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			tr[f].upd(dfn[top[x]],dfn[x],val);
			x=fa[top[x]];
	    }  
	    if(dep[x]>dep[y]) swap(x,y);
	    tr[f].upd(dfn[x]+1,dfn[y],val);
	}
	type query_node(int x,int y,int f)
	{  
		type res=0;
		while(top[x]!=top[y])
		{  
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			res+=tr[f].ask(dfn[top[x]],dfn[x]);
			x=fa[top[x]];
	    }  
	    if(dep[x]>dep[y]) swap(x,y);
	    res+=tr[f].ask(dfn[x]+1,dfn[y]);
	    return res;
	}
	#undef type
}hld;
struct Palindrome_Tree
{
	int len[MAX],nex[MAX][26],fail[MAX],last,s[MAX],tot,n;
	int deep[MAX];
	int newnode(int l)
	{
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0; 
		deep[tot]=0;
		len[tot]=l;
		return tot++;
	}
	void init()
	{
		tot=n=last=0;
		newnode(0);
		newnode(-1);
		s[0]=-1;
		fail[0]=1;
	}
	int get_fail(int x)
	{
		while(s[n-len[x]-1]!=s[n]) x=fail[x];
		return x;
	}
	void add(int t)//attention the type of t is int
	{
		int id,now;
		s[++n]=t;
		now=get_fail(last);
		if(!nex[now][t])
		{
			id=newnode(len[now]+2);
			fail[id]=nex[get_fail(fail[now])][t];
			deep[id]=deep[fail[id]]+1;
			nex[now][t]=id;
		}
		last=nex[now][t];
	}
	int insert(char *a,int f)
	{
		n=last=0;
		s[0]=-1;
		int len=strlen(a);
		for(int i=0;i<len;i++) add(a[i]-'a');
		return last;
	}
	void build_tree()// root is 0
	{
		val[0]=0;
		for(int i=1;i<tot;i++)
		{
			hld.add_edge(fail[i]+1,i+1);
			val[i+1]=len[i];
		}
	}
}pam;
/*
pam.init();
pam.add(t,id); t is int
*/
int last_pos[MAX][2];
int qst[MAX];
char s[MAX];
int main()
{
	int n,i,rt,k,q;
	ll ans,now;
	scanf("%d",&n);
	pam.init();
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		last_pos[i][0]=pam.insert(s,0)+1;
		reverse(s,s+strlen(s));
		last_pos[i][1]=pam.insert(s,1)+1;
	}
	hld.init(pam.tot);
	pam.build_tree();
	rt=1;
	hld.work(rt);
	hld.init_node();
	now=0;
	for(i=1;i<=n;i++)
	{
		hld.modify_node(rt,last_pos[i][0],1,0);
		now+=hld.query_node(rt,last_pos[i][0],1);
		hld.modify_node(rt,last_pos[i][1],1,1);
		now+=hld.query_node(rt,last_pos[i][1],0);
	}
	scanf("%d",&q);
	while(q--)
	{
		ans=now;
		scanf("%d",&k);
		for(i=1;i<=k;i++)
		{
			scanf("%d",&qst[i]);
			ans-=hld.query_node(rt,last_pos[qst[i]][0],1);
			hld.modify_node(rt,last_pos[qst[i]][0],-1,0);
			ans-=hld.query_node(rt,last_pos[qst[i]][1],0);
			hld.modify_node(rt,last_pos[qst[i]][1],-1,1);
		}
		for(i=1;i<=k;i++)
		{
			hld.modify_node(rt,last_pos[qst[i]][0],1,0);
			hld.modify_node(rt,last_pos[qst[i]][1],1,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
