#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	static const ll sd1=131;
	static const ll sd2=233;
	static const int p1=1e9+9;
	static const int p2=998244353;
	ll tmp1[MAX],tmp2[MAX],sumtmp1[MAX],sumtmp2[MAX];
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		int len;
		type ha1,ha2;
		void init(){len=ha1=ha2=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.len=x.len+y.len;
		res.ha1=(x.ha1*tmp1[y.len]+y.ha1)%p1;
		res.ha2=(x.ha2*tmp2[y.len]+y.ha2)%p2;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(tag[id]==-1) return;
		int mid=(l+r)>>1;
		t[ls].ha1=tag[id]*sumtmp1[mid-l]%p1;
		t[ls].ha2=tag[id]*sumtmp2[mid-l]%p2;
		t[rs].ha1=tag[id]*sumtmp1[r-mid-1]%p1;
		t[rs].ha2=tag[id]*sumtmp2[r-mid-1]%p2;
		tag[ls]=tag[rs]=tag[id];
		tag[id]=-1;
	}
	void build(int l,int r,int id)
	{
		tag[id]=-1;
		t[id].init();
		if(l==r)
		{
			t[id]={1,a[l],a[l]};
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
			t[id].ha1=qv*sumtmp1[r-l]%p1;
			t[id].ha2=qv*sumtmp2[r-l]%p2;
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
		tmp1[0]=tmp2[0]=sumtmp1[0]=sumtmp2[0]=1;
		for(int i=1;i<=n;i++)
		{
			tmp1[i]=tmp1[i-1]*sd1%p1;
			tmp2[i]=tmp2[i-1]*sd2%p2;
			sumtmp1[i]=(tmp1[i]+sumtmp1[i-1])%p1;
			sumtmp2[i]=(tmp2[i]+sumtmp2[i-1])%p2;
		}
		build(1,n,1);
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	vector<ll> ask(int l,int r)
	{
		if(l>r) return {-1,-1};
		ql=l;
		qr=r;
		auto it=query(1,n,1);
		return {it.ha1,it.ha2};
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
char s[MAX];
int main()
{
	int n,m,k,q,i,op,l,r,x;
	scanf("%d%d%d",&n,&m,&k);
	q=m+k;
	scanf("%s",s+1);
	for(i=1;i<=n;i++) tr.a[i]=s[i]-'0';
	tr.build(n);
	while(q--)
	{
		scanf("%d%d%d%d",&op,&l,&r,&x);
		if(op==1) tr.upd(l,r,x);
		else
		{
			x=r-l+1-x;
			puts(tr.ask(l,l+x-1)==tr.ask(r-x+1,r)?"YES":"NO");
		}
	}
	return 0;
}
