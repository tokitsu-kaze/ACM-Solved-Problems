#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+9;
const int MAX=1e6+10;
struct Discretization
{
	#define type int
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
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop,sz[MAX<<2];
	bool tag[MAX<<2];
	type h[MAX<<2],v[MAX<<2],tagmul[MAX<<2],qv;
	void pushup(int id)
	{
		h[id]=(h[ls]+h[rs]+1LL*sz[ls]*v[rs])%mod;
		v[id]=(v[ls]+v[rs])%mod;
		sz[id]=sz[ls]+sz[rs];
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		h[ls]=1LL*h[ls]*tagmul[id]%mod;
		h[rs]=1LL*h[rs]*tagmul[id]%mod;
		v[ls]=1LL*v[ls]*tagmul[id]%mod;
		v[rs]=1LL*v[rs]*tagmul[id]%mod;
		tagmul[ls]=1LL*tagmul[ls]*tagmul[id]%mod;
		tagmul[rs]=1LL*tagmul[rs]*tagmul[id]%mod;
		tag[ls]=tag[rs]=tag[id];
		tag[id]=0;
		tagmul[id]=1;
	}
	void build(int l,int r,int id)
	{
		tagmul[id]=1;
		h[id]=v[id]=sz[id]=tag[id]=0;
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
			if(qop==1)
			{
				assert(l==r);
				h[id]=(h[id]+qv+mod)%mod;
				v[id]=(v[id]+qv+mod)%mod;
				if(qv>0) sz[id]++;
				else sz[id]--;
			}
			else
			{
				tag[id]=1;
				tagmul[id]=1LL*tagmul[id]*qv%mod;
				h[id]=1LL*h[id]*qv%mod;
				v[id]=1LL*v[id]*qv%mod;
			}
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
			res=(res+h[id])%mod;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v,type op)
	{
		ql=l;
		qr=r;
		qv=v;
		qop=op;
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
int a[MAX],b[MAX];
int main()
{
	int n,m,x,i,ans,mul,bs;
	bs=233;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		d.add(b[i]);
	}
	d.work();
	for(i=1;i<=m;i++) b[i]=d.get_pos(b[i]);
	tr.build(m);
	mul=1;
	for(i=1;i<=n;i++)
	{
		tr.upd(a[i],a[i],1,1);
		tr.upd(1,m,bs,2);
		mul=1LL*mul*bs%mod;
	}
	ans=tr.ask(1,m);
	tr.build(m);
	for(i=1;i<n;i++)
	{
		tr.upd(b[i],b[i],1,1);
		tr.upd(1,m,bs,2);
	}
	vector<int> res;
	for(i=n;i<=m;i++)
	{
		tr.upd(b[i],b[i],1,1);
		tr.upd(1,m,bs,2);
		if(tr.ask(1,m)==ans) res.push_back(i-n+1);
		tr.upd(b[i-n+1],b[i-n+1],-mul,1);
	}
	printf("%d\n",res.size());
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	return 0;
}
