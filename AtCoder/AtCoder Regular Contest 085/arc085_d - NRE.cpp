#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
		void init(){v=inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=min(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type qv)
	{
		t[id].v=min(t[id].v,qv);
	}
	void pushdown(int l,int r,int id)
	{
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			//init
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
			maintain(l,r,id,qv);
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
int b[MAX],w[MAX],dp[MAX][2];
vector<int> qst[MAX];
int main()
{
	int n,i,q,l,r,tot;
	scanf("%d",&n);
	w[0]=0;
	tot=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		tot+=b[i];
		if(b[i]==0) w[i]=1;
		else w[i]=-1;
		w[i]+=w[i-1];
		qst[i].clear();
	}
	for(i=n+1;i;i--) w[i]=w[i-1];
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		qst[l].push_back(r+1);
	}
	tr.build(n+1);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(i=1;i<=n+1;i++)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
		for(auto &r:qst[i])
		{
			dp[r][1]=min(dp[r][1],dp[i][0]+w[r]-w[i]);
			dp[r][1]=min(dp[r][1],tr.ask(i,r)+w[r]);
			tr.upd(r,r,dp[r][1]-w[r]);
		}
	}
	printf("%d\n",min(dp[n+1][0],dp[n+1][1])+tot);
	return 0;
}
/*
预处理 wi 表示前缀 1-i 全变成 1 的贡献。
dp[i][0/1] 表示处理完 1-i，当前 i 是否作为右端点的最小答案。
不相交就直接从 j<l-1 转移，dp[j]+w[r]-w[l-1]；
相交就是 dp[j]+w[r]-w[j]。
发现如果按 r 排序，转移时会出现从完全包含的右端点转移，这样转移是错的。
但按 l 排序后进行刷表，是对的。感觉这一点很神奇。
感觉就是，按 l 排序，之前的 l 一定小于当前的 l，区间一定是向右延申，只要考虑 r 即可；
但按右端点排序，除了要考虑之前区间的 r，还要考虑之前区间的 l，这样就会出问题。
*/
