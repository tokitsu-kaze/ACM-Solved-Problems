#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e4+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],mn[MAX<<2],tag[MAX<<2],cntmn[MAX<<2],qv;
	void pushup(int id)
	{
		mn[id]=min(mn[ls],mn[rs]);
		if(mn[ls]==mn[rs]) cntmn[id]=cntmn[ls]+cntmn[rs];
		else cntmn[id]=(mn[ls]<mn[rs]?cntmn[ls]:cntmn[rs]);
		v[id]=v[ls]+v[rs];
	}
	void maintain(int pre,int now,int id)
	{
		if(pre==0&&now>0) v[id]+=cntmn[id];
		if(pre>0&&now==0) v[id]-=cntmn[id];
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		maintain(mn[ls],mn[ls]+tag[id],ls);
		maintain(mn[rs],mn[rs]+tag[id],rs);
		mn[ls]+=tag[id];
		mn[rs]+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		if(l==r)
		{
			mn[id]=0;
			cntmn[id]=1;
			v[id]=0;
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
			maintain(mn[id],mn[id]+qv,id);
			mn[id]+=qv;
			tag[id]+=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res+=v[id];
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
const int delta=1e4+1;
const int LEN=1e4+delta;
struct node{int pos,l,r,v;};
int work(vector<node> &res)
{
//	puts("************");
	int i,j,ans,pre,pos;
	sort(res.begin(),res.end(),[&](node x,node y){
		if(x.pos==y.pos) return x.v>y.v;
		return x.pos<y.pos;
	});
	ans=0;
	pre=0;
	pos=1;
	tr.build(LEN);
	for(i=0;i<res.size();i++)
	{
		tr.upd(res[i].l,res[i].r,res[i].v);
		ans+=abs(tr.ask(1,LEN)-pre);
		pos=res[i].pos;
		pre=tr.ask(1,LEN);
	}
//	printf("%d\n",ans);
	return ans;
}
int main()
{
	int n,i,a,b,c,d,ans;
	while(~scanf("%d",&n))
	{
		vector<node> x,y;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			a+=delta;
			b+=delta;
			c+=delta;
			d+=delta;
			x.push_back({a,b,d-1,1});
			x.push_back({c,b,d-1,-1});
			y.push_back({b,a,c-1,1});
			y.push_back({d,a,c-1,-1});
		}
		ans=0;
		ans+=work(x);
		ans+=work(y);
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
1 1 6 4
2 3 4 5
5 3 7 5
*/
