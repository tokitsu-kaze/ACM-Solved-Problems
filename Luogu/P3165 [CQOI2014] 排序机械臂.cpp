#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct FHQ_Treap
{
	#define type pair<int,int>
	struct node
	{
		int ls,rs,fix,sz;
		type v,mn;
		node(){}
		node(type x,int _sz)
		{
			v=mn=x;
			fix=rand();
			sz=_sz;
			ls=rs=0;
		}
	}t[MAX];
	int st[MAX];
	int revtag[MAX];
	int rt,tot;
	void init()
	{
		rt=0;
		srand(time(0));
		tot=0;
		t[0].sz=0;
		t[0].ls=t[0].rs=0;
		t[0].mn={INF,INF};
	}
	int newnode(type v)
	{
		t[++tot]=node(v,1);
		revtag[tot]=0;
		return tot;
	}
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ls].sz+t[t[id].rs].sz+1;
		t[id].mn=min(t[t[id].ls].mn,t[t[id].rs].mn);
		t[id].mn=min(t[id].mn,t[id].v);
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
	int ask_mnpos(int l,int r)
	{
		int ra,rb,rc,id,res;
		type key;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		key=t[rb].mn;
		id=rb;
		res=l-1;
		while(id)
		{
			pushdown(id);
			if(t[id].v==key)
			{
				res+=t[t[id].ls].sz+1;
				break;
			}
			if(t[t[id].ls].mn>key)
			{
				res+=t[t[id].ls].sz+1;
				id=t[id].rs;
			}
			else id=t[id].ls;
		}
		rt=merge(merge(ra,rb),rc);
		return res;
	}
	int size(){return t[rt].sz;}
	#undef type
}tr;
int main()
{
	int n,i,x,pos;
	scanf("%d",&n);
	tr.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		tr.insert(i,{x,i});
	}
	for(i=1;i<=n;i++)
	{
		pos=tr.ask_mnpos(i,n);
		tr.rev(i,pos);
		printf("%d%c",pos," \n"[i==n]);
	}
	return 0;
}
