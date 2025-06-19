#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e6+10;
struct FHQ_Treap
{
	#define type int
	static const type inf=INF;
	struct node
	{
		int ls,rs,fix,sz;
		type v;
		node(){}
		node(type x,int _sz)
		{
			v=x;
			fix=rand();
			sz=_sz;
			ls=rs=0;
		}
	}t[MAX];
	int st[MAX];
	type tag[MAX];
	int revtag[MAX];
	int rt,tot;
	void init()
	{
		rt=0;
		srand(time(0));
		tot=0;
		t[0].sz=0;
		t[0].ls=t[0].rs=0;
		t[0].v=0;
		revtag[0]=0;
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
				
			}
			if(rs)
			{
				
			}
		}
	}
	int build(const string &s)
	{
		int id,k,top=0;
		for(auto &it:s)
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
	void insert(int pos,const string &s)
	{
		int ra,rb;
		split(rt,pos-1,ra,rb);
		rt=merge(merge(ra,build(s)),rb);
	}
	void erase(int l,int r)
	{
		int ra,rb,rc;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
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
	int get(int l,int r)
	{
		int ra,rb,rc,res;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		res=t[rb].v;
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
char s[MAX];
int main()
{
	int n,i,x,now;
	char op[22];
	scanf("%d",&n);
	tr.init();
    now=0;
	while(n--)
	{
		scanf("%s",op);
		if(op[0]=='M')
		{
			scanf("%d",&x);
			now=x;
		}
		else if(op[0]=='I')
		{
			scanf("%d",&x);
			getchar();
			for(i=0;i<x;i++) s[i]=getchar();
			s[x]='\0';
			const string tmp=string(s);
//			cout<<tmp<<endl;
			tr.insert(now+1,tmp);
		}
		else if(op[0]=='D')
		{
			scanf("%d",&x);
			tr.erase(now+1,now+x);
		}
		else if(op[0]=='R')
		{
			scanf("%d",&x);
			tr.rev(now+1,now+x);
		}
		else if(op[0]=='G')
		{
			char res=tr.get(now+1,now+1);
			if(res=='\n') printf("%c",res);
			else printf("%c\n",res);
		}
		else if(op[0]=='P') now--;
		else if(op[0]=='N') now++;
	}
	return 0;
}
