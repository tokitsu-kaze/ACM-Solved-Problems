#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct President_Tree
{
	#define type int
	int root[MAX],ls[MAX<<5],rs[MAX<<5],tot,ql,qr,n;
	type v[MAX<<5],qv,res;
	void init(int _n)
	{
		n=_n;
		ls[0]=rs[0]=v[0]=tot=0;
	}
	int copy_node(int x)
	{
		tot++;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		v[tot]=v[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		v[id]+=qv;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]=0,ls[pre]);
		else update(mid+1,r,rs[id]=0,rs[pre]);
	}
	void query(int l,int r,int id)
	{
		if(!id) return;
		if(l>=ql&&r<=qr)
		{
			res+=v[id];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls[id]);
		if(qr>mid) query(mid+1,r,rs[id]);
	}
	int kth_small(int l,int r,int id,int pre,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int tmp=v[ls[id]]-v[ls[pre]];
		if(tmp>=k) return kth_small(l,mid,ls[id],ls[pre],k);
		else return kth_small(mid+1,r,rs[id],rs[pre],k-tmp);
	}
	int ask_kth_small(int l,int r,int k)
	{
		return kth_small(1,n,root[r],root[l-1],k);
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void create_ver(int now_ver,int pre_ver,int pos,type v)
	{
		root[now_ver]=0;
		update_ver(now_ver,pre_ver,pos,v);
	}
	void update_ver(int now_ver,int pre_ver,int pos,type v)
	{
		ql=qr=pos;
		qv=v;
		update(1,n,root[now_ver],root[pre_ver]);
	}
	type ask_ver(int now_ver,int l,int r)
	{
		res=0;
		if(l>r) return res;
		ql=l;
		qr=r;
		query(1,n,root[now_ver]);
		return res;
	}
}tr;
/*
tr.init(n);
tr.create_ver(now_ver,pre_ver,pos,v);
tr.update_ver(now_ver,pre_ver,pos,v);
tr.copy_ver(now_ver,pre_ver);
tr.ask_kth_small(l,r,k);
*/
int a[MAX];
int main()
{
	int n,q,i,l,r,k;
	scanf("%d%d",&n,&q);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d.add(a[i]);
	}
	d.work();
	for(i=1;i<=n;i++) a[i]=d.get_pos(a[i]);
	tr.init(d.size());
	for(i=1;i<=n;i++) tr.create_ver(i,i-1,a[i],1);
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",d.get_val(tr.ask_kth_small(l,r,k)));
	}
	return 0;
}
