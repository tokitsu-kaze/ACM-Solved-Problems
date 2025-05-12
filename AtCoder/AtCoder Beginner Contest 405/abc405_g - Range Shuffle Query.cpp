#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2.5e5+10;
const int mod=998244353;
int fac[MAX],inv[MAX];
void init(int n)
{
	assert(n<MAX);
	fac[0]=inv[1]=1;
	for(int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%mod;
	for(int i=2;i<=n;i++) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}
struct Block
{
	#define type int
	static const int N=MAX;
	static const int SZ=sqrt(N);
	static const int B=N/SZ+5;
	struct bnode{int cnt;type mul;}valp[N],valb[B],qv,res,null_node;
	int n,bl[B],br[B],bid[N];
	type tag[B];
	void set_null_node(){null_node={0,1};} // init
	void init_point(int x){valp[x]=null_node;}
	void init_block(int id){valb[id]=null_node;}
	void build(int _n)
	{
		int i,j,id,sq;
		n=_n;
		sq=sqrt(n);
		id=0;
		set_null_node();
		for(i=1;i<=n;i+=sq)
		{
			bl[++id]=i;
			br[id]=min(n,i+sq-1);
			init_block(id);
			tag[id]=0;
			for(j=bl[id];j<=br[id];j++)
			{
				bid[j]=id;
				init_point(j);
			}
		}
	}
	void maintain(bnode &now,bnode x)
	{
		if(x.mul!=1) now.mul=1LL*now.mul*x.mul%mod;
		now.cnt+=x.cnt;
	}
	void pushup(int id){maintain(valb[id],qv);}
	void pushdown(int id)
	{
		int i;
		if(tag[id])
		{
			for(i=bl[id];i<=br[id];i++)
			{
				// pushdown
			}
			tag[id]=0;
		}
	}
	void upd_tag(int id)
	{
		// upd_tag
		
	}
	void upd_point(int x){maintain(valp[x],qv);pushup(bid[x]);}
	void upd_block(int id){maintain(valb[id],qv);upd_tag(id);}
	void upd(int l,int r,type mul,int cnt)
	{
		qv={cnt,mul};
		int i;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) upd_point(i);
	    	return;
		}
		pushdown(bid[l]);
		pushdown(bid[r]);
		for(i=l;i<=br[bid[l]];i++) upd_point(i);
		for(i=bl[bid[r]];i<=r;i++) upd_point(i);
		for(i=bid[l]+1;i<=bid[r]-1;i++) upd_block(i);
	}
	void ask_point(int x){maintain(res,valp[x]);}
	void ask_block(int id){maintain(res,valb[id]);}
	type ask(int l,int r)
	{
		if(l>r) return 1;
		res=null_node;
	    int i;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) ask_point(i);
	    	return 1LL*fac[res.cnt]*res.mul%mod;
		}
		pushdown(bid[l]);
		pushdown(bid[r]);
		for(i=l;i<=br[bid[l]];i++) ask_point(i);
		for(i=bl[bid[r]];i<=r;i++) ask_point(i);
		for(i=bid[l]+1;i<=bid[r]-1;i++) ask_block(i);
		return 1LL*fac[res.cnt]*res.mul%mod;
	}
	#undef type
}blk;
struct MO_Algorithm
{
	#define type int
	struct query_info{int l,r,x,id;};
	vector<query_info> qst;
	int n,q,a[MAX],cnt[MAX];
	type ans[MAX];
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_qst(int l,int r,int x,int id){qst.push_back({l,r,x,id});}
	void add(int x)
	{
		cnt[a[x]]++;
		blk.upd(a[x],a[x],inv[cnt[a[x]]],1);
	}
	void del(int x)
	{
		blk.upd(a[x],a[x],cnt[a[x]],-1);
		cnt[a[x]]--;
	}
	void work()
	{
		int i,l,r,sq;
		sq=sqrt(n);
		sort(qst.begin(),qst.end(),[&](query_info a,query_info b){
			if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
			if((a.l/sq)&1) return a.r>b.r;
			else return a.r<b.r;
		});
		for(i=1;i<=n;i++) cnt[i]=0;
		blk.build(n);
		l=1;
		r=0;
		for(auto &q:qst)
		{
			while(l>q.l) add(--l);
			while(r<q.r) add(++r);
			while(l<q.l) del(l++);
			while(r>q.r) del(r--);
			ans[q.id]=blk.ask(1,q.x-1);
		}
		for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
	#undef type
}mo;
/*
O(n*sqrt(n))
mo.init(n,q);
mo.add_qst(l,r,id);
mo.work();
*/
int main()
{
	int n,q,i,l,r,x;
	scanf("%d%d",&n,&q);
	init(n);
	mo.init(n,q);
	for(i=1;i<=n;i++) scanf("%d",&mo.a[i]);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",&l,&r,&x);
		mo.add_qst(l,r,x,i);
	}
	mo.work();
	return 0;
}
