#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type mn[MAX<<2],tag[MAX<<2],cnt[MAX<<2],tag2[MAX<<2],qv;
	ll ans[MAX<<2];
	void pushup(int id)
	{
		mn[id]=min(mn[ls],mn[rs]);
		cnt[id]=0;
		if(mn[ls]==mn[id]) cnt[id]+=cnt[ls];
		if(mn[rs]==mn[id]) cnt[id]+=cnt[rs];
		ans[id]=ans[ls]+ans[rs];
	}
	void pushdown(int id)
	{
		if(tag[id])
		{
			tag[ls]+=tag[id];
			tag[rs]+=tag[id];
			mn[ls]+=tag[id];
			mn[rs]+=tag[id];
			tag[id]=0;
		}
		if(tag2[id])
		{
			if(mn[ls]==mn[id])
			{
				tag2[ls]+=tag2[id];
				ans[ls]+=1ll*tag2[id]*cnt[ls];
			}
			if(mn[rs]==mn[id])
			{
				tag2[rs]+=tag2[id];
				ans[rs]+=1ll*tag2[id]*cnt[rs];
			}
			tag2[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tag[id]=tag2[id]=cnt[id]=ans[id]=0;
		if(l==r)
		{
			mn[id]=l;
			cnt[id]=1;
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
			tag[id]+=qv;
			mn[id]+=qv;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	ll res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res+=ans[id];
			return;
		}
		pushdown(id);
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
	void updtag2()
	{
		tag2[1]++;
		ans[1]+=cnt[1];
	}
	ll ask(int l,int r)
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
struct node{int l,r,id;};
vector<node> qst[MAX];
int a[MAX],stmax[MAX],top1,stmin[MAX],top2;
ll ans[MAX];
int main()
{
	int n,i,q,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		qst[i].clear();
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		qst[r].push_back(node{l,r,i});
		ans[i]=0;
	}
	top1=top2=0;
	stmax[0]=stmin[0]=0;
	tr.build(n);
	for(i=1;i<=n;i++)
	{
		tr.upd(1,n,-1);
		while(top1&&a[stmax[top1]]<a[i])
		{
			tr.upd(stmax[top1-1]+1,stmax[top1],abs(a[i]-a[stmax[top1]]));
			top1--;
		}
		stmax[++top1]=i;
		while(top2&&a[stmin[top2]]>a[i])
		{
			tr.upd(stmin[top2-1]+1,stmin[top2],abs(a[i]-a[stmin[top2]]));
			top2--;
		}
		stmin[++top2]=i;
		tr.updtag2();
		for(auto it:qst[i]) ans[it.id]=tr.ask(it.l,it.r);
	}
	for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
} 
