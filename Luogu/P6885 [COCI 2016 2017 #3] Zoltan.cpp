#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
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
	type a[MAX],tag[MAX<<2],qv,qcnt;
	struct node
	{
		type mx,cnt;
		void init(){mx=0;cnt=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		res.cnt=0;
		if(x.mx==res.mx) res.cnt=(res.cnt+x.cnt)%mod;
		if(y.mx==res.mx) res.cnt=(res.cnt+y.cnt)%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		
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
			if(t[id].mx<qv) t[id]={qv,qcnt};
			else if(t[id].mx==qv) t[id].cnt=(t[id].cnt+qcnt)%mod;
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
	void upd(int l,int r,type v,type cnt)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qcnt=cnt;
		update(1,n,1);
	}
	node ask(int l,int r)
	{
		if(l>r) return null_node;
		ql=l;
		qr=r;
		return query(1,n,1);
	}
	#undef type
	#undef ls
	#undef rs
}tr_up,tr_down;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int a[MAX];
int dp_up[MAX],dp_down[MAX],cnt_up[MAX],cnt_down[MAX];
int main()
{
	int n,i,ans,cnt;
	scanf("%d",&n);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d.add(a[i]);
	}
	d.work();
	for(i=1;i<=n;i++) a[i]=d.get_pos(a[i]);
	tr_up.build(n);
	tr_down.build(n);
	ans=0;
	for(i=n;i;i--)
	{
		auto res_up=tr_up.ask(a[i]+1,n);
		dp_up[i]=res_up.mx+1;
		if(res_up.mx==0) cnt_up[i]=1;
		else cnt_up[i]=res_up.cnt;
		tr_up.upd(a[i],a[i],dp_up[i],cnt_up[i]);
		
		auto res_down=tr_down.ask(1,a[i]-1);
		dp_down[i]=res_down.mx+1;
		if(res_down.mx==0) cnt_down[i]=1;
		else cnt_down[i]=res_down.cnt;
		tr_down.upd(a[i],a[i],dp_down[i],cnt_down[i]);
		
		ans=max(ans,dp_up[i]+dp_down[i]-1);
	}
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(dp_up[i]+dp_down[i]-1==ans) cnt=(cnt+1LL*cnt_up[i]*cnt_down[i])%mod;
//		printf("%d %d %d\n",i,cnt_up[i],cnt_down[i]);
	}
	for(i=1;i<=n-ans;i++) cnt=cnt*2LL%mod;
	printf("%d %d\n",ans,cnt);
	return 0;
}
/*
按顺序操作，后面的数，往前丢，只会越来越前；往后丢，只会越来越后。
也就是说，对于 原数组下标 x，[1,x-1] 的数都无法产生影响。
up[i], down[i] 分别表示：原数组 [i,n] 中最长严格上升和严格下降的子序列。
第一问就是枚举一下 x，ans=max({up[x]+down[x]-1})。
在求第一问的时候顺便求一下方案数：cnt_up[i] 和 cnt_down[i]。
然后枚举一下等于答案的 x，第二问答案为 sum{ cnt_up[x]*cnt_down[x]*2^(n-ans) } 。
*/
