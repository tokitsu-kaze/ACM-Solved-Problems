#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e4+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void clear(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],mx[MAX<<2],tag[MAX<<2],qv;
	void pushup(int id)
	{
		mx[id]=max(mx[ls],mx[rs]);
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		mx[ls]+=tag[id];
		mx[rs]+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=mx[id]=0;
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
			mx[id]+=qv;
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
			res=max(res,mx[id]);
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
struct node{ll x,y,v;};
int main()
{
	int t,n,i,j,l,r;
	ll ans,w,h,x,y,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld%lld",&n,&w,&h);
		d.clear();
		vector<node> res;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&v);
			d.add(y);
			d.add(y-h+1);
			res.push_back({x,y,v});
		}
		d.work();
		sort(res.begin(),res.end(),[&](node a,node b){
			return a.x<b.x;
		});
		tr.build(d.size());
		ans=0;
		for(i=0,j=0;i<n;i++)
		{
			while(j<n&&res[j].x-res[i].x<w)
			{
				l=d.get_pos(res[j].y-h+1);
				r=d.get_pos(res[j].y);
				if(l<r) tr.upd(l,r,res[j].v);
				j++;
			}
			ans=max(ans,tr.ask(1,d.size()));
			l=d.get_pos(res[i].y-h+1);
			r=d.get_pos(res[i].y);
			if(l<r) tr.upd(l,r,-res[i].v);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
