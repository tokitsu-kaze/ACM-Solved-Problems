#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Persistent_Segment_Tree
{
	#define type ll
	int root[MAX],ls[MAX<<5],rs[MAX<<5],tot,ql,qr,n;
	type v[MAX<<5],qv,res;
	void init(int _n)
	{
		n=_n;
		root[0]=0;
		ls[0]=rs[0]=v[0]=tot=0;
	}
	int copy_node(int x)
	{
		++tot;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		v[tot]=v[x];
		return tot;
	}
	void pushup(int id){v[id]=v[ls[id]]+v[rs[id]];}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		if(l==r)
		{
			v[id]=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]=0,ls[pre]);
		else update(mid+1,r,rs[id]=0,rs[pre]);
		pushup(id);
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
	void create_ver(int now_ver,int pre_ver,int pos,type v)
	{
		root[now_ver]=0;
		ql=qr=pos;
		qv=v;
		update(1,n,root[now_ver],root[pre_ver]);
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void update_ver(int now_ver,int pos,type v)
	{
		int now_root=root[now_ver];
		root[now_ver]=0;
		ql=qr=pos;
		qv=v;
		update(1,n,root[now_ver],now_root);
	}
	type ask_sum(int now_ver,int val_l,int val_r)
	{
		ql=val_l;
		qr=val_r;
		res=0;
		query(1,n,root[now_ver]);
		return res;
	}
	#undef type
}tr;
/*
tr.init(n);
tr.create_ver(now_ver,pre_ver,pos,v);
tr.copy_ver(now_ver,pre_ver);
tr.update_ver(now_ver,pos,v);
tr.ask_kth_small(l,r,k);
tr.ask_valsum(l,r,val_l,val_r);
*/
int main()
{
	int n,m,q,i,op,x,y,z,l,r;
	scanf("%d%d%d",&n,&m,&q);
	tr.init(m);
	for(i=1;i<=n;i++) tr.root[i]=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			tr.copy_ver(x,y);
		}
		else if(op==2)
		{
			scanf("%d%d%d",&x,&y,&z);
			tr.update_ver(x,y,z);
		}
		else
		{
			scanf("%d%d%d",&x,&l,&r);
			printf("%lld\n",tr.ask_sum(x,l,r));
		}
	}
	return 0;
}
