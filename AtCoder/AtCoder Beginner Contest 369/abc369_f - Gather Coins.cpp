#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop,qid;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v,id;
		void init(){v=id=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		if(x.v>y.v) res=x;
		else res=y;
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
			if(qv>t[id].v)
			{
				t[id].v=qv;
				t[id].id=qid;
			}
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
	void upd(int x,type v,int id)
	{
		ql=qr=x;
		qv=v;
		qid=id;
		update(1,n,1);
	}
	node ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1);
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
struct node{int y,id;};
vector<node> mp[MAX];
int x[MAX],y[MAX],pre[MAX];
int main()
{
	int n,m,k,i,dp,now,tx,ty;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		mp[x[i]].push_back({y[i],i});
		pre[i]=0;
	}
	pre[0]=0;
	tr.build(m);
	for(i=1;i<=n;i++)
	{
		sort(mp[i].begin(),mp[i].end(),[](node x,node y){
			return x.y<y.y;
		});
		for(auto &it:mp[i])
		{
			auto res=tr.ask(1,it.y);
			dp=res.v+1;
			pre[it.id]=res.id;
			tr.upd(it.y,dp,it.id);
		}
	}
	auto it=tr.ask(1,m);
	printf("%d\n",it.v);
	string ans="";
	now=it.id;
	tx=n;
	ty=m;
	while(now)
	{
//		cout<<now<<" "<<tx<<" "<<ty<<endl;
		while(tx!=x[now]||ty!=y[now])
		{
			if(tx>x[now])
			{
				ans+="D";
				tx--;
			}
			else
			{
				ans+="R";
				ty--;
			}
		}
		now=pre[now];
	}
	while(tx!=1||ty!=1)
	{
		if(tx>1)
		{
			ans+="D";
			tx--;
		}
		else
		{
			ans+="R";
			ty--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
	return 0;
}

