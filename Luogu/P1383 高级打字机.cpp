#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Persistent_Array
{
	#define type int
	struct node{int ls,rs;type v;}t[MAX<<5];
	int root[MAX],tot,qx,n;
	type a[MAX],qv;
	void init(int _n)
	{
		n=_n;
		tot=root[0]=0;
		t[0]={0,0,0};
	}
	void build(int l,int r,int &id)
	{
		if(!id) id=++tot;
		t[id]={0,0,0};
		if(l==r)
		{
			t[id]={0,0,a[l]};
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,t[id].ls);
		build(mid+1,r,t[id].rs);
	}
	int copy_node(int x)
	{
		t[++tot]=t[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		if(l==r)
		{
			t[id].v=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(qx<=mid) update(l,mid,t[id].ls=0,t[pre].ls);
		else update(mid+1,r,t[id].rs=0,t[pre].rs);
	}
	type query(int l,int r,int id)
	{
		if(!id) return 0;
		if(l==r) return t[id].v;
		int mid=(l+r)>>1;
		if(qx<=mid) return query(l,mid,t[id].ls);
		else return query(mid+1,r,t[id].rs);
	}
	void build_ver(int now_ver){build(1,n,root[now_ver]=0);}
	void clear_ver(int now_ver){root[now_ver]=0;}
	void copy_ver(int now_ver,int pre_ver){root[now_ver]=root[pre_ver];}
	void create_ver(int now_ver,int pre_ver,int pos,type v)
	{
		root[now_ver]=0;
		qx=pos;
		qv=v;
		update(1,n,root[now_ver],root[pre_ver]);
	}
	void update_ver(int now_ver,int pos,type v)
	{
		qx=pos;
		qv=v;
		update(1,n,root[now_ver],root[now_ver]);
	}
	type ask(int now_ver,int pos)
	{
		qx=pos;
		return query(1,n,root[now_ver]);
	}
	#undef type
}pa;
/*
pa.init(n);
pa.build_ver(now_ver);
pa.clear_ver(now_ver);
pa.copy_ver(now_ver,pre_ver);
pa.create_ver(now_ver,pre_ver,pos,v);
pa.update_ver(now_ver,pos,v);
pa.ask(now_ver,pos);
*/
int len[MAX];
int main()
{
	int q,i,x,tot;
	char op[3];
	scanf("%d",&q);
	pa.init(q);
	pa.build_ver(0);
	tot=0;
	len[0]=0;
	while(q--)
	{
		scanf("%s",op);
		if(op[0]=='T')
		{
			scanf("%s",op);
			tot++;
			len[tot]=len[tot-1]+1;
			pa.create_ver(tot,tot-1,len[tot],op[0]-'a');
		}
		else
		{
			scanf("%d",&x);
			if(op[0]=='U')
			{
				tot++;
				pa.copy_ver(tot,tot-1-x);
				len[tot]=len[tot-1-x];
			}
			else printf("%c\n",'a'+pa.ask(tot,x));
		}
	}
	return 0;
}
