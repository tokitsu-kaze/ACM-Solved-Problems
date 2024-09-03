#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct Segment_Tree
{
	#define type int
	static const int LOG=21;
	struct node
	{
		type mx;
		void init(){mx=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,qop;
	int st[MAX*LOG],top;
	type ql,qr,qv,n,tag[MAX*LOG];
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
		tag[id]=0;
		return id;
	}
	node merge_node(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls[id]],t[rs[id]]);}
	void pushdown(type l,type r,int id)
	{
		if(!tag[id] || !id) return;
		if(ls[id])
		{
			t[ls[id]].mx+=tag[id];
			tag[ls[id]]+=tag[id];
		}
		if(rs[id])
		{
			t[rs[id]].mx+=tag[id];
			tag[rs[id]]+=tag[id];
		}
		tag[id]=0;
	}
	void update(type l,type r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			t[id].mx=max(t[id].mx,qv);
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
	int merge(type l,type r,int x,int y,type mxx,type mxy)
	{
		if(!x && !y) return 0;
		pushdown(l,r,x);
		pushdown(l,r,y);
		if(!y)
		{
			t[x].mx+=mxy;
			tag[x]+=mxy;
			return x;
		}
		if(!x)
		{
			t[y].mx+=mxx;
			tag[y]+=mxx;
			return y;
		}
		if(l==r)
		{
			t[x].mx+=max(t[y].mx,mxy);
			delnode(y);
			return x;
		}
		type mid=(l+r)>>1;
		ls[x]=merge(l,mid,ls[x],ls[y],max(mxx,t[rs[x]].mx),
									  max(mxy,t[rs[y]].mx));
		rs[x]=merge(mid+1,r,rs[x],rs[y],mxx,mxy);
		pushup(x);
		delnode(y);
		return x;
	}
	void merge_segtree(int y)
	{
		root[rt]=merge(1,n,root[rt],root[y],0,0);
		root[y]=0;
	}
	void upd(type l,type r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root[rt]);
	}
	type ask(type l,type r)
	{
		ql=l;
		qr=r;
		return query(1,n,root[rt]).mx;
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
int w[MAX],tot;
void dfs(int x)
{
	int dp;
	dp=1;
	tr[x].build();
	for(auto &to:mp[x])
	{
		dfs(to);
		dp+=tr[to].ask(w[x],tot);
		tr[x].merge_segtree(to);
	}
	tr[x].upd(w[x],w[x],dp);
//	cout<<x<<" "<<dp<<endl;
}
int main()
{
	int n,i,fa;
	scanf("%d",&n);
	d.init();
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%d",&w[i]);
		d.add(w[i]);
	}
	d.work();
	tot=d.size();
	for(i=1;i<=n;i++) w[i]=d.get_pos(w[i]);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&fa);
		mp[fa].push_back(i);
	}
	tr.init(tot);
	dfs(1);
	printf("%d\n",tr.ask(1,tot));
	return 0;
}

