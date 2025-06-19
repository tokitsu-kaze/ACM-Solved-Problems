#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=max(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].v+=tag[id];
		t[rs].v+=tag[id];
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
			t[id].v=a[l];
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
			t[id].v+=qv;
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
		if(l>r) return null_node.v;
		ql=l;
		qr=r;
		return query(1,n,1).v;
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
vector<int> mp[MAX],leaf;
int v[MAX],l[MAX],r[MAX],tot,sz[MAX];
ll sum[MAX];
void dfs0(int x,int fa,ll now)
{
	l[x]=++tot;
	sum[x]=now+v[x];
	sz[x]=0;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs0(to,x,now+v[x]);
		sz[x]+=sz[to];
	}
	r[x]=tot;
	if(l[x]==r[x])
	{
		leaf.push_back(x);
		sz[x]=1;
	}
}
ll k,ans;
struct node{int leafsz;ll val;};
vector<node> res;
void dfs(int x,int fa)
{
	ll mx,tmp;
	mx=tr.ask(l[x],r[x]);
	if(mx>=k)
	{
		tmp=min(1LL*v[x],mx-k);
		ans+=tmp;
		tr.upd(l[x],r[x],-tmp);
		res.push_back({sz[x],v[x]-tmp});
	}
	else res.push_back({sz[x],v[x]});
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
}
int main()
{
	int T,n,q,i,a,b;
	ll now,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			mp[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		tot=0;
		leaf.clear();
		dfs0(1,0,0);
		while(q--)
		{
			scanf("%lld",&k);
			for(i=1;i<=n;i++) tr.a[l[i]]=sum[i];
			tr.build(n);
			ans=0;
			res.clear();
			dfs(1,0);
			now=ans;
			for(auto &it:leaf)
			{
				tmp=tr.ask(l[it],l[it]);
				now-=k-tmp;
			}
			if(now>0)
			{
				sort(res.begin(),res.end(),[](node x,node y){
					return x.leafsz>y.leafsz;
				});
				for(auto &it:res)
				{
					// now+?-?*leafsz<=0
					if(it.leafsz==1) continue;
					tmp=min(it.val,(now+it.leafsz-2)/(it.leafsz-1));
					ans+=tmp;
					now=now+tmp-tmp*it.leafsz;
					if(now<=0) break;
				}
			}
			if(now>0) ans=-1;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
1
3 10
4 3 3
1 2 1 3
1 2 3 4 5 6 7 8 9 10

-1
-1
-1
-1
4
2
0
0
0
0
*/
