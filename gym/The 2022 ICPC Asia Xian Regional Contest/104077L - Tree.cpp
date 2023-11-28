#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mx;
		int pos;
		void init()
		{
			
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		if(x.mx>y.mx) res=x;
		else res=y;
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].mx+=tag[id];
		tag[ls]+=tag[id];
		t[rs].mx+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mx=0;
			t[id].pos=l;
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
			t[id].mx+=qv;
			tag[id]+=qv;
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
		return merge(query(l,mid,ls),query(mid+1,r,rs));
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
		auto res=query(1,n,1);
		return res.pos;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
vector<int> mp[MAX];
int fa[MAX],h[MAX],v[MAX],l[MAX],r[MAX],id[MAX],dfn;
int leafcnt;
void dfs(int x,int fa)
{
	h[x]=h[fa]+1;
	v[x]=1;
	l[x]=++dfn;
	id[dfn]=x;
	for(auto &to:mp[x])
	{
		dfs(to,x);
		v[x]=max(v[x],v[to]+1);
	}
	r[x]=dfn;
	if(!mp[x].size())
	{
		tr.upd(l[x],r[x],h[x]);
		leafcnt++;
	}
}
int main()
{
	int t,n,i,ans,now,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		fa[1]=0;
		for(i=2;i<=n;i++)
		{
			scanf("%d",&fa[i]);
			mp[fa[i]].push_back(i);
		}
		h[0]=0;
		dfn=0;
		tr.build(n);
		leafcnt=0;
		dfs(1,0);
		set<pair<int,int>> s;
		for(i=1;i<=n;i++) s.insert({v[i],i});
		ans=(*s.rbegin()).first;
		cnt=0;
		while(leafcnt>0)
		{
			leafcnt--;
			now=id[tr.ask(1,n)];
			while(now)
			{
				if(v[now]==-1) break;
				s.erase({v[now],now});
				v[now]=-1;
				tr.upd(l[now],r[now],-1);
				now=fa[now];
			}
			cnt++;
			if(s.size()) ans=min(ans,cnt+(*s.rbegin()).first);
			else ans=min(ans,cnt);
			if(cnt>ans) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
