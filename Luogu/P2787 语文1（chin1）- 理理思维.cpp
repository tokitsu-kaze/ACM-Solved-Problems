#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=x.v+y.v;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(tag[id]==-1) return;
		int mid=(l+r)>>1;
		t[ls].v=tag[id]*(mid-l+1);
		t[rs].v=tag[id]*(r-mid);
		tag[ls]=tag[rs]=tag[id];
		tag[id]=-1;
	}
	void build(int l,int r,int id)
	{
		tag[id]=-1;
		t[id].init();
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
			t[id].v=qv*(r-l+1);
			tag[id]=qv;
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
	void cov(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
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
}tr[26];
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
char s[MAX];
int main()
{
	int n,m,op,x,y,i,j,cnt[26],pre;
	char t[2];
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=0;i<26;i++) tr[i].build(n);
	for(i=1;i<=n;i++)
	{
		if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
		tr[s[i]-'a'].cov(i,i,1);
	}
	while(m--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1 || op==2)
		{
			scanf("%s",t);
			if(t[0]>='A' && t[0]<='Z') t[0]=t[0]-'A'+'a';
		}
		if(op==1) printf("%d\n",tr[t[0]-'a'].ask(x,y));
		else if(op==2)
		{
			for(i=0;i<26;i++) tr[i].cov(x,y,0);
			tr[t[0]-'a'].cov(x,y,1);
		}
		else
		{
			for(i=0;i<26;i++)
			{
				cnt[i]=tr[i].ask(x,y);
				tr[i].cov(x,y,0);
			}
			pre=x;
			for(i=0;i<26;i++)
			{
				if(cnt[i]==0) continue;
				tr[i].cov(pre,pre+cnt[i]-1,1);
				pre+=cnt[i];
			}
		}
	}
	return 0;
}
