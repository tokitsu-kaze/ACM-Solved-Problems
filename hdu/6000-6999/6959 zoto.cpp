#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Block
{
	#define type int
	static const int N=1e5+5;
	static const int SZ=sqrt(N);
	static const int B=N/SZ+5;
	struct bnode{type v;}valp[N],valb[B],qv,res,null_node;
	int n,bl[B],br[B],bid[N];
	type tag[B];
	void set_null_node(){null_node={0};} // init
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
		now.v+=x.v;
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
	void upd(int l,int r,type v)
	{
		qv={v};
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
		if(l>r) return null_node.v;
		res=null_node;
	    int i;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) ask_point(i);
		}
		else
		{
			pushdown(bid[l]);
			pushdown(bid[r]);
			for(i=l;i<=br[bid[l]];i++) ask_point(i);
			for(i=bl[bid[r]];i<=r;i++) ask_point(i);
			for(i=bid[l]+1;i<=bid[r]-1;i++) ask_block(i);
		}
		return res.v;
	}
	#undef type
}blk;
struct MO_Algorithm
{
	#define type int
	static const int N=1e5+5;
	static const int Q=1e5+5;
	struct query_info{int l,r,a,b,id;};
	vector<query_info> qst;
	int n,q,s[N],cnt[N];
	type ans[Q],res;
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_qst(query_info x){qst.push_back(x);}
	void add(int x)
	{
		cnt[s[x]]++;
		if(cnt[s[x]]==1) blk.upd(s[x],s[x],1);
	}
	void del(int x)
	{
		cnt[s[x]]--;
		if(cnt[s[x]]==0) blk.upd(s[x],s[x],-1);
	}
	void work()
	{
		int i,l,r,sq;
		sq=n/sqrt(q);
		sort(qst.begin(),qst.end(),[&](query_info a,query_info b){
			if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
			if((a.l/sq)&1) return a.r>b.r;
			else return a.r<b.r;
		});
		for(i=1;i<=n;i++) cnt[i]=0;
		blk.build(n);
		l=1;
		r=0;
		res=0;
		for(auto &q:qst)
		{
			while(l>q.l) add(--l);
			while(r<q.r) add(++r);
			while(l<q.l) del(l++);
			while(r>q.r) del(r--);
			ans[q.id]=blk.ask(q.a,q.b);
		}
		for(i=1;i<=q;i++) cout<<ans[i]<<"\n";
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
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,q,i,l,r,a,b;
	cin>>T;
	while(T--)
	{
		cin>>n>>q;
		mo.init(n,q);
		for(i=1;i<=n;i++) cin>>mo.s[i];
		for(i=1;i<=q;i++)
		{
			cin>>l>>a>>r>>b;
			mo.add_qst({l,r,a,b,i});
		}
		mo.work();
	}
	return 0;
}
