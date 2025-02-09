#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct Segment_Tree
{
	#define type ll
	static const int LOG=22;
	struct node
	{
		type sum,cnt;
		void init(){sum=cnt=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,qop;
	int st[MAX*LOG],top;
	type ql,qr,qv,n;
	Segment_Tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(type _n)
	{
		n=_n;
		rt=1;
		tot=top=0;
		t[0].init();
		ls[0]=rs[0]=0;
		null_node.init();
	}
	void build(){root[rt]=0;}
	void delnode(int id){st[top++]=id;}
	int newnode()
	{
		int id;
		id=top?st[--top]:++tot;
		t[id].init();
		ls[id]=rs[id]=0;
		return id;
	}
	node merge_node(node x,node y)
	{
		node res;
		res.sum=x.sum+y.sum;
		res.cnt=x.cnt+y.cnt;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls[id]],t[rs[id]]);}
	void pushdown(type l,type r,int id)
	{
		return;
	}
	void update(type l,type r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			t[id].sum+=qv;
			t[id].cnt++;
			return;
		}
		pushdown(l,r,id);
		type mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	node query(type l,type r,int id)
	{
		if(!id) return null_node;
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		type mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls[id]);
		if(ql>mid) return query(mid+1,r,rs[id]);
		return merge_node(query(l,mid,ls[id]),query(mid+1,r,rs[id]));
	}
	int split(type l,type r,int &id)
	{
		int x;
		if(!id) return 0;
		if(l>=ql&&r<=qr)
		{
			x=id;
			id=0;
			return x;
		}
		x=newnode();
		int mid=(l+r)>>1;
		if(ql<=mid) ls[x]=split(l,mid,ls[id]);
		if(qr>mid) rs[x]=split(mid+1,r,rs[id]);
		pushup(x);
		pushup(id);
		return x;
	}
	int merge(type l,type r,int x,int y)
	{
		if(!x||!y) return x+y;
		if(l==r)
		{
			t[x].sum+=t[y].sum;
			t[x].cnt+=t[y].cnt;
			delnode(y);
			return x;
		}
		type mid=(l+r)>>1;
		ls[x]=merge(l,mid,ls[x],ls[y]);
		rs[x]=merge(mid+1,r,rs[x],rs[y]);
		pushup(x);
		delnode(y);
		return x;
	}
	void split_segtree(type l,type r,int new_tree)
	{
		ql=l;
		qr=r;
		root[new_tree]=split(1,n,root[rt]);
	}
	void merge_segtree(int y)
	{
		root[rt]=merge(1,n,root[rt],root[y]);
		root[y]=0;
	}
	void upd(type l,type r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root[rt]);
	}
	node ask(type l,type r)
	{
		if(l>r) return null_node;
		ql=l;
		qr=r;
		return query(1,n,root[rt]);
	}
	#undef type
}tr;
/*
tr.init(n);
tr.build();
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
---------
tr[x].build();
tr[x].merge_segtree(y);
tr[x].split_segtree(l,r,new_tree);
*/
vector<int> mp[MAX];
vector<int> s[MAX];
int dep[MAX],n;
ll ans;
void work(int x,int now,int tid)
{
	auto it=tr[tid].ask(1,dep[x]);
	ans+=2LL*(it.sum-1LL*dep[now]*it.cnt)-it.cnt;
	if(dep[x]+1<=n)
	{
		it=tr[tid].ask(dep[x]+1,n);
		ans+=(2LL*(dep[x]-dep[now])-1)*it.cnt;
	}
}
void dfs(int x,int fa,int h)
{
	tr[x].build();
	s[x].clear();
	dep[x]=h;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,h+1);
		if(s[x].size()<s[to].size())
		{
			for(auto &it:s[x])
			{
				s[to].push_back(it);
				work(it,x,to);
			}
			swap(s[x],s[to]);
		}
		else
		{
			for(auto &it:s[to])
			{
				s[x].push_back(it);
				work(it,x,x);
			}
		}
		tr[x].merge_segtree(to);
	}
	tr[x].upd(dep[x],dep[x],dep[x]);
	s[x].push_back(x);
}
int main()
{
	int T,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		ans=0;
		tr.init(n);
		dfs(1,0,1);
		printf("%lld\n",ans);
	}
	return 0;
}
