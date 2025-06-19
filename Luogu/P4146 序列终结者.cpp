#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=50000+10;
struct FHQ_Treap
{
	#define type ll
	static const type inf=LLINF;
	struct node
	{
		int ls,rs,fix,sz;
		type mx,v;
		node(){}
		node(type x,int _sz)
		{
			mx=v=x;
			fix=rand();
			sz=_sz;
			ls=rs=0;
		}
	}t[MAX];
	int st[MAX];
	int revtag[MAX];
	type tag[MAX];
	int rt,tot;
	void init()
	{
		rt=0;
		srand(time(0));
		tot=0;
		t[0].sz=0;
		t[0].ls=t[0].rs=0;
		t[0].v=t[0].mx=-inf;
		revtag[0]=tag[0]=0;
	}
	int newnode(type v)
	{
		t[++tot]=node(v,1);
		revtag[tot]=tag[tot]=0;
		return tot;
	}
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ls].sz+t[t[id].rs].sz+1;
		t[id].mx=max({t[t[id].ls].mx,t[t[id].rs].mx,t[id].v});
	}
	void pushdown(int id)
	{
		if(revtag[id])
		{
			int ls=t[id].ls;
			int rs=t[id].rs;
			swap(t[ls].ls,t[ls].rs);
			swap(t[rs].ls,t[rs].rs);
			revtag[ls]^=revtag[id];
			revtag[rs]^=revtag[id];
			revtag[id]=0;
		}
		if(tag[id])
		{
			int ls=t[id].ls;
			int rs=t[id].rs;
			if(ls)
			{
				t[ls].v+=tag[id];
				t[ls].mx+=tag[id];
				tag[ls]+=tag[id];
			}
			if(rs)
			{
				t[rs].v+=tag[id];
				t[rs].mx+=tag[id];
				tag[rs]+=tag[id];
			}
			tag[id]=0;
		}
	}
	int build(vector<type> &a)
	{
		int id,k,top=0;
		for(auto &it:a)
		{
			id=newnode(it);
			k=top;
			while(k>0&&t[st[k-1]].fix>t[id].fix) pushup(st[--k]);
			if(k) t[st[k-1]].rs=id;
			if(k<top) t[id].ls=st[k];
			st[k++]=id;
			top=k;
		}
		while(top>0) pushup(st[--top]);
		return st[0];
	}
	void split(int id,int pos,int &x,int &y)
	{
		if(!id)
		{
			x=y=0;
			return;
		}
		pushdown(id);
		int tmp=t[t[id].ls].sz+1;
		if(tmp<=pos)
		{
			x=id;
			split(t[id].rs,pos-tmp,t[id].rs,y);
		}
		else
		{
			y=id;
			split(t[id].ls,pos,x,t[id].ls);
		}
		pushup(id);
	}
	int merge(int x,int y)
	{
		if(!x||!y) return x|y;
		int id;
		if(t[x].fix<t[y].fix)
		{
			pushdown(x);
			id=x;
			t[x].rs=merge(t[x].rs,y);
		}
		else
		{
			pushdown(y);
			id=y;
			t[y].ls=merge(x,t[y].ls);
		}
		pushup(id);
		return id;
	}
	void insert(int pos,type v)
	{
		int ra,rb;
		split(rt,pos-1,ra,rb);
		rt=merge(merge(ra,newnode(v)),rb);
	}
	void insert(int pos,vector<type> a)
	{
		int ra,rb;
		split(rt,pos-1,ra,rb);
		rt=merge(merge(ra,build(a)),rb);
	}
	void erase(int pos,type v)
	{
		int ra,rb,rc;
		split(rt,pos,ra,rc);
		split(ra,pos-1,ra,rb);
		rt=merge(ra,rc);
	}
	void rev(int l,int r)
	{
		int ra,rb,rc;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		revtag[rb]^=1;
		swap(t[rb].ls,t[rb].rs);
		rt=merge(merge(ra,rb),rc);
	}
	void upd(int l,int r,type qv)
	{
		int ra,rb,rc;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		tag[rb]+=qv;
		t[rb].v+=qv;
		t[rb].mx+=qv;
		rt=merge(merge(ra,rb),rc);
	}
	type ask(int l,int r)
	{
		int ra,rb,rc;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		type res=t[rb].mx;
		rt=merge(merge(ra,rb),rc);
		return res;
	}
	vector<int> res;
	void dfs(int id)
	{
		if(!id) return;
		pushdown(id);
		dfs(t[id].ls);
		res.push_back(t[id].v);
		dfs(t[id].rs);
	}
	int size(){return t[rt].sz;}
	#undef type
}tr;
/*
tr.init();
tr.insert(pos,a) // pos,pos+1,...,pos+a.size-1
*/
int main()
{
	int n,m,i,op,l,r,x;
	scanf("%d%d",&n,&m);
	tr.init();
	tr.insert(1,vector<ll>(n,0));
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			tr.upd(l,r,x);
		}
		else if(op==2) tr.rev(l,r);
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
