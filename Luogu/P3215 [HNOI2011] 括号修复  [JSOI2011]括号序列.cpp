#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct FHQ_Treap
{
	#define type int
	static const type inf=INF;
	struct node
	{
		int ls,rs,fix,sz;
		type premn,premx,sufmn,sufmx,sum,v;
		int replace_tag,rev_tag,invert_tag;
		node(){}
		node(type val,int _sz)
		{
			fix=rand();
			sz=_sz;
			ls=rs=0;
			v=sum=val;
			premn=sufmn=min(0,val);
			premx=sufmx=max(0,val);
			replace_tag=rev_tag=invert_tag=0;
		}
	}t[MAX];
	int st[MAX];
	int rt,tot;
	void init()
	{
		rt=0;
		srand(time(0));
		tot=0;
		t[0]=node(0,0);
	}
	int newnode(type v)
	{
		t[++tot]=node(v,1);
		return tot;
	}
	void pushup(int id)  
	{  
		int ls=t[id].ls;
		int rs=t[id].rs;
		t[id].sz=t[ls].sz+t[rs].sz+1;
		t[id].sum=t[ls].sum+t[rs].sum+t[id].v;
		t[id].premx=max(t[ls].premx,t[ls].sum+t[id].v+t[rs].premx);
		t[id].premn=min(t[ls].premn,t[ls].sum+t[id].v+t[rs].premn);
		t[id].sufmx=max(t[rs].sufmx,t[ls].sufmx+t[id].v+t[rs].sum);
		t[id].sufmn=min(t[rs].sufmn,t[ls].sufmn+t[id].v+t[rs].sum);
	}
	void maintain_replace(int id,type val)
	{
		t[id].v=val;
		t[id].sum=t[id].sz*val;
		t[id].premn=t[id].sufmn=min(0,t[id].sum);
		t[id].premx=t[id].sufmx=max(0,t[id].sum);
		t[id].rev_tag=0;
		t[id].invert_tag=0;
		t[id].replace_tag=val;
	}
	void maintain_invert(int id)
	{
		swap(t[id].premx,t[id].premn);
		swap(t[id].sufmx,t[id].sufmn);
		t[id].premx*=-1;
		t[id].premn*=-1;
		t[id].sufmx*=-1;
		t[id].sufmn*=-1;
		t[id].sum*=-1;
		t[id].v*=-1;
		t[id].invert_tag^=1;
	}
	void maintain_rev(int id)
	{
		swap(t[id].ls,t[id].rs);
		swap(t[id].premx,t[id].sufmx);
		swap(t[id].premn,t[id].sufmn);
		t[id].rev_tag^=1;
	}
	void pushdown(int id)
	{
		int ls=t[id].ls;
		int rs=t[id].rs;
		if(t[id].replace_tag)
		{
			int val=t[id].replace_tag;
			if(ls) maintain_replace(ls,val);
			if(rs) maintain_replace(rs,val);
			t[id].replace_tag=0;
		}
		if(t[id].invert_tag)
		{
			if(ls) maintain_invert(ls);
			if(rs) maintain_invert(rs);
			t[id].invert_tag=0;
		}
		if(t[id].rev_tag)
		{
			if(ls) maintain_rev(ls);
			if(rs) maintain_rev(rs);
			t[id].rev_tag=0;
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
			id=x;
			pushdown(x);
			t[x].rs=merge(t[x].rs,y);
		}
		else
		{
			id=y;
			pushdown(y);
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
	vector<int> res;
	void dfs(int id)
	{
		if(!id) return;
		pushdown(id);
		dfs(t[id].ls);
	//	res.push_back(t[id].v);
	//	printf("%d ",t[id].v);
		dfs(t[id].rs);
	}
	void replace(int l,int r,type val)
	{
		int ra,rb,rc;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		maintain_replace(rb,val);
		rt=merge(merge(ra,rb),rc);
	}
	void rev(int l,int r)
	{
		int ra,rb,rc;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		maintain_rev(rb);
		rt=merge(merge(ra,rb),rc);
	}
	void invert(int l,int r)
	{
		int ra,rb,rc;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		maintain_invert(rb);
		rt=merge(merge(ra,rb),rc);
	}
	type ask(int l,int r)
	{
		int ra,rb,rc;
		type ans;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		ans=(abs(t[rb].premn)+1)/2+(t[rb].sufmx+1)/2;
		rt=merge(merge(ra,rb),rc);
		return ans;
	}
	int size(){return t[rt].sz;}
	#undef type
}tr;
char s[MAX];
int main()
{
	int n,q,l,r,i;
	char op[11],tmp[3];
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	tr.init();
	vector<int> a(n);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='(') a[i-1]=1;
		else a[i-1]=-1;
	}
	tr.insert(1,a);
	while(q--)
	{
	//	tr.dfs(tr.rt);
	//	puts("");
		scanf("%s%d%d",op,&l,&r);
		if(op[0]=='R')
		{
			scanf("%s",tmp);
			tr.replace(l,r,tmp[0]=='('?1:-1);
		}
		else if(op[0]=='S') tr.rev(l,r);
		else if(op[0]=='I') tr.invert(l,r);
		else printf("%d\n",tr.ask(l,r));
	}
	return 0;
}
