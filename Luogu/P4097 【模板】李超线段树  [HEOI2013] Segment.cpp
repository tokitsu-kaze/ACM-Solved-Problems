#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-9;
const int MAX=39989+10;
struct LiChao_Segment_Tree
{
	#define type double
	#define inf 1e18
	#define ls (id<<1)
	#define rs (id<<1|1)
	static const int MIN_TAG=0;
	static const int MAX_TAG=1;
	int TAG;
	#define init_val (TAG==MIN_TAG?inf:-inf)
	struct line{type k,b;int id;}sg[MAX<<2];
	type v[MAX<<2];
	bool ext[MAX<<2];
	int ql,qr,n;
	type cal(const line &l,const int &x){return l.k*x+l.b;}
	int sgn(const type &x){return abs(x)<eps?0:(x>0?1:-1);}
	int cmp_min(const type &x,const type &y){return sgn(y-x);}
	int cmp_max(const type &x,const type &y){return sgn(x-y);}
	int cmp(const type &x,const type &y){return TAG==MIN_TAG?cmp_min(x,y):cmp_max(x,y);}
	type ckres(const type &x,const type &y){return TAG==MIN_TAG?min(x,y):max(x,y);}
	void build(int l,int r,int id)
	{
		ext[id]=0;
		v[id]=init_val;
		sg[id]={0,init_val};
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void pushup(int id)
	{
		v[id]=ckres(v[id],v[ls]);
		v[id]=ckres(v[id],v[rs]);
	}
	void pushdown(int l,int r,int id,line qv)
	{
		int cl,cr,mid;
		if(!ext[id])
		{
			ext[id]=1;
			sg[id]=qv;
			goto pushdown_end;
		}
		mid=(l+r)>>1;
		if(cmp(cal(qv,mid),cal(sg[id],mid))==1) swap(qv,sg[id]);
		else if(cmp(cal(qv,mid),cal(sg[id],mid))==0 && sg[id].id>qv.id) swap(qv,sg[id]);
		cl=cmp(cal(qv,l),cal(sg[id],l));
		cr=cmp(cal(qv,r),cal(sg[id],r));
		if(cl>=0&&cr>=0)
		{
			if(cl==0&&cr==0) sg[id].id=min(sg[id].id,qv.id);
			else sg[id]=qv;
			goto pushdown_end;
		}
		if(cl==1||(cl==0&&sg[id].id>qv.id)) pushdown(l,mid,ls,qv);
		else if(cr==1||(cr==0&&sg[id].id>qv.id)) pushdown(mid+1,r,rs,qv);
	pushdown_end:
		v[id]=ckres(cal(sg[id],l),cal(sg[id],r));
		if(l!=r) pushup(id);
	}
	void update(int l,int r,int id,line qv)
	{
		if(l>=ql&&r<=qr)
		{
			pushdown(l,r,id,qv);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls,qv);
		if(qr>mid) update(mid+1,r,rs,qv);
		v[id]=ckres(cal(sg[id],l),cal(sg[id],r));
		pushup(id);
	}
	type res;
	int pos;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			if(cmp(v[id],res)==1)
			{
				res=v[id];
				pos=sg[id].id;
			}
			else if(cmp(v[id],res)==0) pos=min(pos,sg[id].id);
			return;
		}
		type tmp;
		tmp=cal(sg[id],max(l,ql));
		if(cmp(tmp,res)==1)
		{
			res=tmp;
			pos=sg[id].id;
		}
		else if(cmp(tmp,res)==0) pos=min(pos,sg[id].id);
		
		tmp=cal(sg[id],min(r,qr));
		if(cmp(tmp,res)==1)
		{
			res=tmp;
			pos=sg[id].id;
		}
		else if(cmp(tmp,res)==0) pos=min(pos,sg[id].id);
		
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n,int _TAG){n=_n;TAG=_TAG;build(1,n,1);}
	void upd(int l,int r,type k,type b,int id)
	{
		ql=l;
		qr=r;
		update(1,n,1,{k,b,id});
	}
	int ask(int l,int r)
	{
		ql=l;
		qr=r;
		res=init_val;
		pos=0;
		query(1,n,1);
		return pos;
	}
	void dfs(int l,int r,int id)
	{
		cout<<l<<" "<<r<<" "<<sg[id].k<<" "<<sg[id].b<<endl;
		if(l==r) return;
		int mid=(l+r)>>1;
		dfs(l,mid,ls);
		dfs(mid+1,r,rs);
	}
	#undef type
	#undef init_val
	#undef ls
	#undef rs
}tr;
/*
upd:O(log^2), ask:O(log)

tr.build(n,LiChao_Segment_Tree::MIN_TAG);
tr.build(n,LiChao_Segment_Tree::MAX_TAG);
tr.upd(l,r,k,b);
tr.ask(l,r);
*/
int main()
{
	int n,op,x,x0,y0,x1,y1,lst,tot;
	double k,b;
	scanf("%d",&n);
	tr.build(39989,LiChao_Segment_Tree::MAX_TAG);
	lst=tot=0;
	while(n--)
	{
		scanf("%d",&op);
		if(op==0)
		{
			scanf("%d",&x);
			x=(x+lst-1)%39989+1;
			lst=tr.ask(x,x);
			printf("%d\n",lst);
		}
		else
		{
			tot++;
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			x0=(x0+lst-1)%39989+1;
			y0=(y0+lst-1)%1000000000+1;
			x1=(x1+lst-1)%39989+1;
			y1=(y1+lst-1)%1000000000+1;
			if(x0>x1)
			{
				swap(x0,x1);
				swap(y0,y1);
			}
			if(x0==x1)
			{
				k=0;
				b=max(y0,y1);
			}
			else
			{
				k=(y1-y0)*1.0/(x1-x0);
				b=y1-k*x1;
			}
			tr.upd(x0,x1,k,b,tot);
		}
	}
	return 0;
}
