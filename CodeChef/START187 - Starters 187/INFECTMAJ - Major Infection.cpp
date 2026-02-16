#include<bits/stdc++.h>
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
		type mx;
		void init(){mx=-1;}
	}t[MAX<<2],null_node;
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
struct node{
	int pos,type;
	// type=0 -> a[i]==a[i-1] or a[i]==a[i-2]&&a[i-1]>a[i]
	// type=1 -> a[i]==a[i-2]&&a[i-1]<a[i]
};
int a[MAX];
vector<node> res[MAX];
int main()
{
	int T,n,i,j,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			res[i].clear();
			tr.a[i]=a[i];
		}
		tr.build(n);
		a[n+1]=0;
		for(i=2;i<=n;i++)
		{
			if(a[i]==a[i-1]) res[a[i]].push_back({i,0});
			else if(a[i]==a[i-2])
			{
				if(a[i-1]>a[i]) res[a[i]].push_back({i,0});
				else res[a[i]].push_back({i,1});
			}
		}
		r=1;
		for(i=1;i<=n;i++)
		{
			if(res[i].size()==0) continue;
			for(auto &it:res[i])
			{
				if(it.pos<r) continue;
				if(it.type==1)
				{
					if(tr.ask(r,it.pos)<=i)
					{
						r=it.pos;
						continue;
					}
				}
				j=it.pos;
				while(j>=r)
				{
					if(tr.ask(r,j)>i)
					{
						tr.upd(j,j,i);
						j--;
					}
					else break;
				}
				r=it.pos;
				for(j=it.pos+1;j<=n;j++)
				{
					if(a[j]>=i) tr.upd(j,j,i);
					else break;
					r=j;
				}
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",tr.ask(i,i)," \n"[i==n]);
	}
	return 0;
}
/*
1
14
8 9 6 9 6 10 4 10 6 9 6 9 3 9

把操作称为推平。 
把所有可以推平的位置存一下。
从小到大枚举值，然后枚举所有可以推平的位置 pos。
维护一个 R 表示前 1-R 都推平了。
如果 pos < R，说明已经被推平过了；
否则看是否是 a[pos]=a[pos-2] && a[pos-1] < a[pos] 这个情况，
如果是的话，查询 R 到 i 的最大值，如果最大值 <= a[i] 就不能推平；
如果不是，就先往前推平，更新线段树和 R，再暴力往后推平，更新线段树和 R。
*/

