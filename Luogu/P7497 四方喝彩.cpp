#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
struct Segment_Tree
{
	#define type ll
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop,bancnt[MAX<<2];
	type a[MAX],tagadd[MAX<<2],tagmul[MAX<<2],qv;
	struct node
	{
		type sum,bansum,sz;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.sum=(x.sum+y.sum)%mod;
		res.bansum=(x.bansum+y.bansum)%mod;
		res.sz=x.sz+y.sz;
		return res;
	}
	void pushup(int id)
	{
		if(bancnt[id]) return;
		t[id]=merge_node(t[ls],t[rs]);
	}
	void maintain(int nex,int id)
	{
		if(tagmul[id]!=1)
		{
			t[nex].sum=t[nex].sum*tagmul[id]%mod;
			tagmul[nex]=tagmul[nex]*tagmul[id]%mod;
			tagadd[nex]=tagadd[nex]*tagmul[id]%mod;
		}
		if(tagadd[id]!=0)
		{
			t[nex].sum=(t[nex].sum+t[nex].sz*tagadd[id])%mod;
			tagadd[nex]=(tagadd[nex]+tagadd[id])%mod;
		}
	}
	void pushdown(int l,int r,int id)
	{
		if(bancnt[ls]==0) maintain(ls,id);
		if(bancnt[rs]==0) maintain(rs,id);
		tagadd[id]=0;
		tagmul[id]=1;
	}
	void build(int l,int r,int id)
	{
		tagadd[id]=0;
		tagmul[id]=1;
		bancnt[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id]={a[l],0,1};
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(qop<=2 && bancnt[id]) return;
		if(l>=ql&&r<=qr)
		{
			if(qop==1)
			{
				t[id].sum=(t[id].sum+t[id].sz*qv)%mod;
				tagadd[id]=(tagadd[id]+qv)%mod;
			}
			else if(qop==2)
			{
				t[id].sum=t[id].sum*qv%mod;
				tagmul[id]=tagmul[id]*qv%mod;
				tagadd[id]=tagadd[id]*qv%mod;
			}
			else
			{
				bancnt[id]+=qv;
				if(qv==1)
				{
					if(l!=r) pushdown(l,r,id);
					if(bancnt[id]==1)
					{
						t[id].bansum=(t[id].bansum+t[id].sum)%mod;
						t[id].sum=0;
						t[id].sz=0;
					}
				}
				else
				{
					if(bancnt[id]==0)
					{
						if(l==r)
						{
							t[id].sum=t[id].bansum;
							t[id].bansum=0;
							t[id].sz=1;
						}
						else pushup(id);
					}
				}
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
		if(l>r) return 0;
		ql=l;
		qr=r;
		auto res=query(1,n,1);
		return (res.sum+res.bansum)%mod;
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
struct node{int l,r;};
vector<node> unban[MAX];
int main()
{
	int n,q,op,l,r,x,i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	for(i=1;i<=q;i++) unban[i].clear();
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op<=3) scanf("%d",&x);
		for(auto &it:unban[i]) tr.upd(it.l,it.r,-1,3);
		if(op<=2) tr.upd(l,r,x,op);
		else if(op==3)
		{
			if(i+x+1<=q) unban[i+x+1].push_back({l,r});
			tr.upd(l,r,1,op);
		}
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
/*
封锁操作可能会叠加，所以，维护一个变量表示被封锁几次；
另外再维护一个变量表示区间内没有被封锁的数量。
乘法时，被封锁的不能再乘，所以还要分开记录两个sum。
以及注意 pushdown 和 pushup 的时机。
*/
