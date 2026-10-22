#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e5+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return upper_bound(all(a),x)-a.begin();} // <= x
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tagadd[MAX<<2],tagmax[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=max(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type qv,int qop)
	{
		if(qop==1)
		{
			t[id].v+=qv;
			tagadd[id]+=qv;
			if(tagmax[id]) tagmax[id]+=qv;
		}
		else
		{
			t[id].v=max(t[id].v,qv);
			tagmax[id]=max(tagmax[id],qv);
		}
	}
	void pushdown(int l,int r,int id)
	{
		int mid=(l+r)>>1;
		if(tagadd[id])
		{
			maintain(l,mid,ls,tagadd[id],1);
			maintain(mid+1,r,rs,tagadd[id],1);
			tagadd[id]=0;
		}
		if(tagmax[id])
		{
			maintain(l,mid,ls,tagmax[id],2);
			maintain(mid+1,r,rs,tagmax[id],2);
			tagmax[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tagadd[id]=tagmax[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].v=0;
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
			maintain(l,r,id,qv,qop);
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
	void upd_add(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qop=1;
		update(1,n,1);
	}
	void upd_max(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qop=2;
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
}tr[2];
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
struct node{int l,type;};
vector<node> res[MAX];
int l[MAX],r[MAX],type[MAX],dp[MAX][2];
int main()
{
	int n,i,j,cnt[2],mx;
	scanf("%d",&n);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&l[i],&r[i],&type[i]);
		type[i]--;
		d.add(l[i]-1);
		d.add(l[i]);
		d.add(r[i]);
	}
	d.work();
	for(i=1;i<=d.size();i++) res[i].clear();
	for(i=1;i<=n;i++)
	{
		l[i]=d.get_pos(l[i]);
		r[i]=d.get_pos(r[i]);
		res[r[i]].push_back({l[i],type[i]});
	}
	n=d.size();
	tr[0].build(n);
	tr[1].build(n);
	for(i=1;i<=n;i++)
	{
		sort(res[i].begin(),res[i].end(),[](node x,node y){
			return x.l<y.l;
		});
		for(auto &it:res[i])
		{
			tr[it.type].upd_max(i,n,tr[!it.type].ask(1,it.l-1)+1);
			tr[!it.type].upd_add(1,it.l-1,1);
		}
	}
	printf("%d\n",max(tr[0].ask(1,n),tr[1].ask(1,n)));
	return 0;
}
/*
dp[i][0/1] 表示最后选的是 type=0/1 的线段 x，rx<=i 的最大答案。
尝试将线段挂在左端点，发现有问题，所以把线段挂在右端点，
- 更新不同 type 的 dp，因为当前线段可以往上叠，不会更新不同 type 线段的 r，
所以 不同 type 的 r 在区间 [1,l-1] 都是合法的，这个区间 dp 值 +1；
- 更新相同 type 的 dp，区间 [r,n] 的 dp 值更新为：max{dp[!type][1~l-1]}+1。
*/
