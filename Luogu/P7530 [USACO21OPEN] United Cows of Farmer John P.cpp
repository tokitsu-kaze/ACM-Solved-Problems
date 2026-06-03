#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v,sz;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=x.v+y.v;
		res.sz=x.sz+y.sz;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].v+=tag[id]*t[ls].sz;
		t[rs].v+=tag[id]*t[rs].sz;
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id]={0,0};
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
			if(qop==1)
			{
				t[id].v+=qv*t[id].sz;
				tag[id]+=qv;
			}
			else if(qop==2)
			{
				t[id].v=0;
				t[id].sz=qv;
			}
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
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qop=1;
		update(1,n,1);
	}
	void set(int x,type v)
	{
		ql=x;
		qr=x;
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
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int pre[MAX],ppre[MAX];
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) pre[i]=ppre[i]=0;
	tr.build(n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(pre[x]) tr.set(pre[x],0);
		if(pre[x]) tr.upd(ppre[x]+1,pre[x]-1,-1);
		ans+=tr.ask(pre[x]+1,i-1);
		tr.upd(pre[x]+1,i-1,1);
		tr.set(i,1);
		ppre[x]=pre[x];
		pre[x]=i;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
考虑枚举右端点，维护前面每个点作为左端点时，有多少个可用的中间点。
考虑加入一个点 x=a[i] 会产生哪些变化。
1. pre[x] 再也不能作为左端点；
2. pre[x] 不能作为中间点，要把这部分贡献撤销；
3. i 作为右端点时，可行的左端点范围是 [pre[x]+1,i-1]；
4. i 可以作为 [pre[x]+1,i-1] 内左端点的中间点；
5. i 可以作为左端点。
不能作为左端点相当于做删除操作，
维护一个sz[]表示子树未被删除的叶子节点个数。
*/
