#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,qop,ql,qr,qv;
	type a[MAX],mx[MAX<<2],len[MAX<<2],revtag[MAX<<2],tag[MAX<<2];
	type lv1[MAX<<2],rv1[MAX<<2],v1[MAX<<2],md1[MAX<<2],mx1[MAX<<2];
	type lv0[MAX<<2],rv0[MAX<<2],v0[MAX<<2],md0[MAX<<2],mx0[MAX<<2];
	
	void pushup(int id)
	{
		v1[id]=v1[ls]+v1[rs];
		v0[id]=v0[ls]+v0[rs];
		
		lv1[id]=lv1[ls];
		if(v1[ls]==len[ls]) lv1[id]=v1[ls]+lv1[rs];
		rv1[id]=rv1[rs];
		if(v1[rs]==len[rs]) rv1[id]=v1[rs]+rv1[ls];
		lv0[id]=lv0[ls];
		if(v0[ls]==len[ls]) lv0[id]=v0[ls]+lv0[rs];
		rv0[id]=rv0[rs];
		if(v0[rs]==len[rs]) rv0[id]=v0[rs]+rv0[ls];
		
		md1[id]=rv1[ls]+lv1[rs];
		md0[id]=rv0[ls]+lv0[rs];
		
		mx1[id]=max({mx1[ls],mx1[rs],md1[id],lv1[id],rv1[id]});
		mx0[id]=max({mx0[ls],mx0[rs],md0[id],lv0[id],rv0[id]});
	}
	void pushdown(int l,int r,int id)
	{
		if(tag[id]!=-1)
		{
			if(tag[id])
			{
				mx1[ls]=md1[ls]=lv1[ls]=rv1[ls]=v1[ls]=len[ls];
				mx0[ls]=md0[ls]=lv0[ls]=rv0[ls]=v0[ls]=0;
				
				mx1[rs]=md1[rs]=lv1[rs]=rv1[rs]=v1[rs]=len[rs];
				mx0[rs]=md0[rs]=lv0[rs]=rv0[rs]=v0[rs]=0;
			}
			else
			{
				mx1[ls]=md1[ls]=lv1[ls]=rv1[ls]=v1[ls]=0;
				mx0[ls]=md0[ls]=lv0[ls]=rv0[ls]=v0[ls]=len[ls];
				
				mx1[rs]=md1[rs]=lv1[rs]=rv1[rs]=v1[rs]=0;
				mx0[rs]=md0[rs]=lv0[rs]=rv0[rs]=v0[rs]=len[rs];
			}
			tag[ls]=tag[rs]=tag[id];
			tag[id]=-1;
			revtag[ls]=revtag[rs]=0;
		}
		if(revtag[id])
		{
			swap(v1[ls],v0[ls]);
			swap(lv1[ls],lv0[ls]);
			swap(rv1[ls],rv0[ls]);
			swap(md1[ls],md0[ls]);
			swap(mx1[ls],mx0[ls]);
			revtag[ls]^=1;
			
			swap(v1[rs],v0[rs]);
			swap(lv1[rs],lv0[rs]);
			swap(rv1[rs],rv0[rs]);
			swap(md1[rs],md0[rs]);
			swap(mx1[rs],mx0[rs]);
			revtag[rs]^=1;
			
			revtag[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		revtag[id]=0;
		tag[id]=-1;
		len[id]=r-l+1;
		if(l==r)
		{
			if(a[l]) mx1[id]=md1[id]=lv1[id]=rv1[id]=v1[id]=1;
			else mx0[id]=md0[id]=lv0[id]=rv0[id]=v0[id]=1;
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
			if(qop==1)
			{
				swap(v1[id],v0[id]);
				swap(lv1[id],lv0[id]);
				swap(rv1[id],rv0[id]);
				swap(md1[id],md0[id]);
				swap(mx1[id],mx0[id]);
				revtag[id]^=1;
			}
			else
			{
				if(qv)
				{
					mx1[id]=md1[id]=lv1[id]=rv1[id]=v1[id]=len[id];
					mx0[id]=md0[id]=lv0[id]=rv0[id]=v0[id]=0;
				}
				else
				{
					mx1[id]=md1[id]=lv1[id]=rv1[id]=v1[id]=0;
					mx0[id]=md0[id]=lv0[id]=rv0[id]=v0[id]=len[id];
				}
				tag[id]=qv;
				revtag[id]=0;
			}
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res,rmx;
	void query_sum(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res+=v1[id];
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query_sum(l,mid,ls);
		if(qr>mid) query_sum(mid+1,r,rs);
	}
	void query_max(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res=max(res,mx1[id]);
			res=max(res,rmx+lv1[id]);
			if(v1[id]==len[id]) rmx=rmx+v1[id];
			else rmx=rv1[id];
			rmx=max(rmx,rv1[id]);
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query_max(l,mid,ls);
		if(qr>mid) query_max(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void rev(int l,int r)
	{
		qop=1;
		ql=l;
		qr=r;
		update(1,n,1);
	}
	void set(int l,int r,type v)
	{
		qop=2;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask_sum(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=0;
		query_sum(1,n,1);
		return res;
	}
	type ask_max(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=0;
		rmx=0;
		query_max(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int main()
{
	int n,q,i,l,r,op;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&tr.a[i]);
	tr.build(n);
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		l++;
		r++;
		if(op==0) tr.set(l,r,0);
		else if(op==1) tr.set(l,r,1);
		else if(op==2) tr.rev(l,r);
		else if(op==3) printf("%d\n",tr.ask_sum(l,r));
		else printf("%d\n",tr.ask_max(l,r));
	}
	return 0;
}
