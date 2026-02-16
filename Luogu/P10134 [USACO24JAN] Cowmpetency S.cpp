#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mx;
		void init(){mx=0;}
	}t[MAX<<2],null_node;
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	node merge_node(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mx=a[l];
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
			t[id].mx=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge_node(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.mx;
		ql=l;
		qr=r;
		return query(1,n,1).mx;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int v[MAX],mx[MAX];
vector<int> qst[MAX];
int main()
{
	int t,n,q,limt,i,a,b,ok,now_mx,mx,mx2,pos;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&q,&limt);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			tr.a[i]=v[i];
			qst[i].clear();
		}
		while(q--)
		{
			scanf("%d%d",&a,&b);
			qst[b].push_back(a);
		}
		set<int> s;
		s.insert(0);
		s.insert(INF);
		ok=1;
		tr.build(n);
		for(i=1;i<=n&&ok;i++)
		{
			sort(qst[i].begin(),qst[i].end());
			now_mx=0;
			for(auto &it:qst[i])
			{
				mx=tr.ask(1,it);
				if(it!=i-1)
				{
					mx2=tr.ask(it+1,i-1);
					if(mx2>mx)
					{
						pos=*(--s.upper_bound(it));
						if(pos==0)
						{
							ok=0;
							break;
						}
						v[pos]=mx2;
						tr.upd(pos,pos,v[pos]);
						mx=v[pos];
					}
				}
				now_mx=max(now_mx,mx);
			}
			if(v[i])
			{
				if(v[i]<=now_mx) ok=0;
			}
			else
			{
				s.insert(i);
				v[i]=now_mx+1;
				tr.upd(i,i,v[i]);
			}
		}
		for(i=1;i<=n&&ok;i++)
		{
			if(v[i]>limt) ok=0;
			for(auto &it:qst[i])
			{
				mx=tr.ask(1,it);
				if(v[i]<=mx) ok=0;
				if(it!=i-1&&tr.ask(it+1,i-1)>mx) ok=0;
			}
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++) printf("%d%c",v[i]," \n"[i==n]);
	}
	return 0;
}
