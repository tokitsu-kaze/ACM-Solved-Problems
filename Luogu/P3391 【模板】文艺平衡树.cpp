#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fll;
const int MAX=1e6+1e5+10;
struct Splay
{
	#define type int
	const type inf=INF;
	struct node
	{
		int ch[2],fa,sz,cnt,tag;
		type v;
		node(){}
		node(type x,int _fa)
		{
			v=x;
			sz=cnt=1;
			fa=_fa;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];
	int tot,root,n;
	void pushup(int id)
	{
		t[id].sz=t[t[id].ch[0]].sz+t[t[id].ch[1]].sz+t[id].cnt;
	}
	void pushdown(int id)
	{
		int ls=t[id].ch[0];
		int rs=t[id].ch[1];
		if(t[id].tag)
		{
			t[ls].tag^=1;
			t[rs].tag^=1;
			swap(t[ls].ch[0],t[ls].ch[1]);
			swap(t[rs].ch[0],t[rs].ch[1]);
			t[id].tag=0;
		}
	}
	void rotate(int x)
	{
		int y,z,k;
		y=t[x].fa;
		z=t[y].fa;
		k=(x==t[y].ch[1]);
		t[y].ch[k]=t[x].ch[k^1];
		if(t[x].ch[k^1]) t[t[x].ch[k^1]].fa=y;
		t[x].ch[k^1]=y;
		t[y].fa=x;
		t[x].fa=z;
		if(z) t[z].ch[y==t[z].ch[1]]=x;
		pushup(y);
		pushup(x);
	}
	void splay(int x,int goal)
	{
		int y,z;
		while(t[x].fa!=goal)
		{
			y=t[x].fa;
			z=t[y].fa;
			if(z!=goal)
			{
				if((t[z].ch[0]==y)^(t[y].ch[0]==x)) rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
		if(goal==0) root=x;
	}
	
	type kth(int k)//k small
	{
		int id=root;
		while(id)
		{
			pushdown(id);
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k) break;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
				id=t[id].ch[1];
			}
		}
		splay(id,0);
		return id;
	}
	int find(int x){return kth(x+1);}
	int split(int l,int r)
	{
		int x,y;
		x=find(l-1);
		y=find(r+1);
		splay(x,0);
		splay(y,x);
		return t[y].ch[0];
	}
	type a[MAX];
	int build(int l,int r,int fa)
	{
		if(l>r) return 0;
		int id,mid;
		id=++tot;
		mid=(l+r)>>1;
		t[id]=node(a[mid],fa);
		t[id].ch[0]=build(l,mid-1,id);
		t[id].ch[1]=build(mid+1,r,id);
		pushup(id);
		return id;
	}
	void insert(int pos,vector<type> &nums)
	{
		int x,y,z,i;
		for(i=0;i<nums.size();i++) a[i+1]=nums[i];
		z=build(1,nums.size(),0);
		x=find(pos);
		y=find(pos+1);
		splay(x,0);
		splay(y,x);
		t[y].ch[0]=z;
		t[z].fa=y;
		pushup(y);
		pushup(x);
	}
	void init()
	{
		root=tot=0;
		t[0].sz=t[0].cnt=t[0].fa=0;
		memset(t[0].ch,0,sizeof t[0].ch);
		a[0]=-inf;
		a[1]=inf;
		root=build(0,1,0);
	}
	void upd(int l,int r)
	{
		int x,fa;
		x=split(l,r);
		fa=t[x].fa;
		t[x].tag^=1;
		swap(t[x].ch[0],t[x].ch[1]);
		pushup(fa);
		pushup(t[fa].fa);
	}
	vector<int> res;
	void dfs(int id)
	{
		if(!id) return;
		pushdown(id);
		dfs(t[id].ch[0]);
		res.push_back(t[id].v);
		dfs(t[id].ch[1]);
	}
	#undef type
}tr; //tr.init();
int main()
{
	int n,q,i,l,r;
	scanf("%d%d",&n,&q);
	vector<int> a(n);
	for(i=0;i<n;i++) a[i]=i+1;
	tr.init();
	tr.insert(0,a);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		tr.upd(l,r);
	}
	tr.dfs(tr.root);
	for(i=1;i<=n;i++) printf("%d%c",tr.res[i]," \n"[i==n]);
	return 0;
}

