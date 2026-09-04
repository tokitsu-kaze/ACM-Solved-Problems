#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Persistent_Segment_Tree
{
	#define type ll
	int root[MAX],ls[MAX<<5],rs[MAX<<5],sz[MAX<<5],tot,ql,qr,n;
	type v[MAX<<5],qv,res;
	void init(int _n)
	{
		n=_n;
		root[0]=0;
		ls[0]=rs[0]=v[0]=sz[0]=tot=0;
	}
	int copy_node(int x)
	{
		++tot;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		v[tot]=v[x];
		sz[tot]=sz[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		v[id]+=qv;
		sz[id]++;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]=0,ls[pre]);
		else update(mid+1,r,rs[id]=0,rs[pre]);
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
	type query(int l,int r,int id1,int id2,int k)
	{
		if(l==r) return 1LL*k*l;
		int mid=(l+r)>>1;
		int tmp=sz[rs[id1]]+sz[rs[id2]];
		if(tmp>=k) return query(mid+1,r,rs[id1],rs[id2],k);
		else return v[rs[id1]]+v[rs[id2]]
					+query(l,mid,ls[id1],ls[id2],k-tmp);
	}
	type kth_big_sum(int rt1,int rt2,int k)
	{
		return query(1,n,root[rt1],root[rt2],k);
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
int a[MAX];
int main()
{
	int n,m,i,x,l,r;
	scanf("%d%d",&n,&m);
	tr.init(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tr.create_ver(i,i-1,a[i],a[i]);
	}
	tr.copy_ver(n+1,0);
	for(i=2;i<=m+1;i++)
	{
		scanf("%d%d%d",&x,&l,&r);
		tr.create_ver(n+i,n+i-1,x,x);
		printf("%lld\n",tr.kth_big_sum(r,n+i,r)
					   -tr.kth_big_sum(l-1,n+i,l-1));
	}
	return 0;
}
/*
操作的本质是换一个最小值出来。
把区间查询差分一下，问题转化成：
求 a[1..k] 与 之前询问所有的 xi 合起来的集合中，前 k 大数之和。
分别用主席树和权值线段树维护，求的时候要一起走。
为了实现方便，直接建两个主席树。
*/
