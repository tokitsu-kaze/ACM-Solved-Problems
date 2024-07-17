#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
/*----*/
const ll offset=1e9;
const ll sd1=131;
const ll sd2=233;
const int p1=1e9+9;
const int p2=998244353;
ll t1[MAX],t2[MAX],sumt1[MAX],sumt2[MAX];
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
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
		res.ha1=(x.ha1*t1[y.len]+y.ha1)%p1;
		res.ha2=(x.ha2*t2[y.len]+y.ha2)%p2;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(tag[id]==-1) return;
		int mid=(l+r)>>1;
		t[ls].ha1=tag[id]*sumt1[mid-l]%p1;
		t[ls].ha2=tag[id]*sumt2[mid-l]%p2;
		t[rs].ha1=tag[id]*sumt1[r-mid-1]%p1;
		t[rs].ha2=tag[id]*sumt2[r-mid-1]%p2;
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
			t[id].ha1=qv*sumt1[r-l]%p1;
			t[id].ha2=qv*sumt2[r-l]%p2;
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
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	node ask(int l,int r)
	{
		if(l>r) return node();
		ql=l;
		qr=r;
		return query(1,n,1);
	}
	#undef type
	#undef ls
	#undef rs
}tr,trrev;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int tot;
ll res[25*MAX];
void init(int n)
{
	int i,j;
	t1[0]=t2[0]=sumt1[0]=sumt2[0]=1;
	for(i=1;i<=n;i++)
	{
		t1[i]=t1[i-1]*sd1%p1;
		t2[i]=t2[i-1]*sd2%p2;
		sumt1[i]=(t1[i]+sumt1[i-1])%p1;
		sumt2[i]=(t2[i]+sumt2[i-1])%p2;
	}
	tot=0;
	res[tot++]=0;
	for(j=-25;j<=25;j++)
	{
		if(j==0) continue;
		for(i=0;i<=n/2;i++)
		{
			res[tot++]=((j*t1[i]%p1+p1)%p1*offset)+(j*t2[i]%p2+p2)%p2;
		}
	}
	sort(res,res+tot);
}
bool ck(int l,int r,int n)
{
	Segment_Tree::node res1,res2;
	int len,pos;
	ll now;
    len=r-l+1;
    res1=tr.ask(l,l+len/2-1);
    res2=trrev.ask(n-r+1,(n-r+1)+len/2-1);
    now=((res1.ha1-res2.ha1+p1)%p1)*offset+((res1.ha2-res2.ha2+p2)%p2);
    pos=lower_bound(res,res+tot,now)-res;
    if(pos<tot && res[pos]==now) return true;
    return false;
}
char s[MAX];
int main()
{
	int n,q,i,op,l,r;
	char tmp[2];
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	init(n);
	for(i=1;i<=n;i++) trrev.a[n-i+1]=tr.a[i]=s[i]-'a';
	tr.build(n);
	trrev.build(n);
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			if(ck(l,r,n)) puts("YES");
			else puts("NO");
		}
		else
		{
			scanf("%s",tmp);
			tr.upd(l,r,tmp[0]-'a');
			trrev.upd(n-r+1,n-l+1,tmp[0]-'a');
		}
	}
	return 0;
}
