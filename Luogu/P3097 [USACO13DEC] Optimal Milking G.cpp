#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e4+10;
struct Matrix
{
	#define type ll
	static const int N=2;
	int n;
	type c[N][N];
	Matrix(){}
	Matrix(int _n,type v=0)
	{
		int i,j;
		n=_n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=v;
			}
		}
	}
	void init_identity_matrix(type val)
	{
		for(int i=0;i<n;i++) c[i][i]=val;
	}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					res.c[i][j]=max(res.c[i][j],c[i][k]+b.c[k][j]);
				}
			}
		}
		return res;
	}
	void print()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<c[i][j]<<" \n"[j+1==n];
			}
		}
	}
};
struct Segment_Tree
{
	#define type ll
	static const type inf=LLINF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		Matrix v;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=x.v*y.v;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		
	}
	Matrix create_mat(type v)
	{
		Matrix res(2,0);
		res.c[0][0]=0;
		res.c[0][1]=v;
		res.c[1][0]=0;
		res.c[1][1]=-inf;
		return res;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].v=create_mat(a[l]);
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
			a[l]=qv;
			t[id].v=create_mat(a[l]);
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
	void upd(int x,type v)
	{
		ql=x;
		qr=x;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		ql=l;
		qr=r;
		Matrix res=query(1,n,1).v;
		Matrix a0(2,0);
		res=a0*res;
		return max(res.c[0][0],res.c[0][1]);
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
int main()
{
	int n,q,x,y,i;
	ll ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	ans=0;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		tr.upd(x,y);
		ans+=tr.ask(1,n);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
dp[i][1]=dp[i-1][0]+a[i];

				[0,a[i]]
[i-1,0  i-1,1]* [0,-inf]
*/
