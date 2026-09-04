#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type mn;
		void init(){mn=inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].mn+=tag[id];
		t[rs].mn+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mn=0;
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
			t[id].mn+=qv;
			tag[id]+=qv;
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
		n=_n+1;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l+1;
		qr=r+1;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.mn;
		ql=l+1;
		qr=r+1;
		return query(1,n,1).mn;
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
int a[MAX],tag[MAX],cnt[MAX];
int main()
{
	int T,n,i,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		tr.build(n);
		for(i=0;i<=n;i++) tag[i]=cnt[i]=0;
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]<ans)
			{
				if(tag[a[i]]) tr.upd(0,(a[i]-1)/2,1);
				else
				{
					tr.upd(0,a[i]-1,1);
					tr.upd(a[i],a[i],tr.inf);
					tag[a[i]]=1;
				}
			}
			else
			{
				if(a[i]<=n) cnt[a[i]]++;
				tr.upd(0,min(n,(a[i]-1)/2),1);
			}
			while(1)
			{
				if(cnt[ans])
				{
					cnt[ans]--;
					tr.upd(0,(ans-1)/2,-1);
					if(tr.ask(0,ans-1)<0)
					{
						tr.upd(0,(ans-1)/2,1);
						cnt[ans]++;
						break;
					}
					tag[ans]=1;
					tr.upd(ans,ans,tr.inf);
					ans++;
				}
				else
				{
					if(tr.ask(0,ans)-1<0) break;
					tr.upd(0,ans,-1);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
// easy 直接，二分答案就行。
