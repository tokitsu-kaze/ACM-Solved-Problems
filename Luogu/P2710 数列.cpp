#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fll;
const int MAX=5e5+10;
struct Splay
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int ch[2],fa,sz,cnt,rev,tag;
		type v,sum,lsum,rsum,mxsum;
	}t[MAX];
	int tot,root,n;
	queue<int> pool;
	void maintain(int id,type v)
	{
		t[id].v=v;
		t[id].sum=t[id].sz*t[id].v;
		t[id].lsum=t[id].rsum=max(0ll,t[id].sum);
		t[id].mxsum=max(t[id].v,t[id].sum);
	}
	void pushup(int id)
	{
		int ls=t[id].ch[0];
		int rs=t[id].ch[1];
		t[id].sz=t[ls].sz+t[rs].sz+t[id].cnt;
		t[id].sum=t[ls].sum+t[rs].sum+t[id].v;
		t[id].lsum=max(t[ls].sum+t[id].v+t[rs].lsum,t[ls].lsum);
		t[id].rsum=max(t[rs].sum+t[id].v+t[ls].rsum,t[rs].rsum);
		t[id].mxsum=max({t[ls].mxsum,t[rs].mxsum,t[ls].rsum+t[id].v+t[rs].lsum});
	}
	void pushdown(int id)
	{
		int ls=t[id].ch[0];
		int rs=t[id].ch[1];
		if(t[id].rev)
		{
			t[ls].rev^=1;
			t[rs].rev^=1;
			swap(t[ls].lsum,t[ls].rsum);
			swap(t[rs].lsum,t[rs].rsum);
			swap(t[ls].ch[0],t[ls].ch[1]);
			swap(t[rs].ch[0],t[rs].ch[1]);
			t[id].rev=0;
		}
		if(t[id].tag)
		{
			if(ls)
			{
				maintain(ls,t[id].v);
				t[ls].tag=1;
			}
			if(rs)
			{
				maintain(rs,t[id].v);
				t[rs].tag=1;
			}
			t[id].tag=0;
		}
	}
	int newnode(type v,int fa)
	{
		int id;
		if(pool.size()>0)
		{
			id=pool.front();
			pool.pop();
		}
		else id=++tot;
		memset(t[id].ch,0,sizeof t[id].ch);
		t[id].fa=fa;
		t[id].sz=t[id].cnt=1;
		t[id].tag=t[id].rev=0;
		maintain(id,v);
		return id;
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
		mid=(l+r)>>1;
		id=newnode(a[mid],fa);
		t[id].ch[0]=build(l,mid-1,id);
		t[id].ch[1]=build(mid+1,r,id);
		pushup(id);
		return id;
	}
	void init_null_node()
	{
		t[0].sz=t[0].cnt=t[0].fa=0;
		memset(t[0].ch,0,sizeof t[0].ch);
		t[0].v=t[0].sum=0;
		t[0].lsum=t[0].rsum=0;
		t[0].mxsum=-inf;
	}
	void init()
	{
		root=tot=0;
		while(!pool.empty()) pool.pop();
		init_null_node();
		a[0]=a[1]=inf;
		root=build(0,1,0);
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
	void del(int id)
	{
		if(!id) return;
		pool.push(id);
		del(t[id].ch[0]);
		del(t[id].ch[1]);
	}
	void erase(int l,int r)
	{
		int x,fa;
		x=split(l,r);
		fa=t[x].fa;
		t[fa].ch[0]=0;
		del(x);
		pushup(fa);
		pushup(t[fa].fa);
	}
	void upd(int l,int r,type qv)
	{
		int x,fa;
		x=split(l,r);
		fa=t[x].fa;
		t[x].tag=1;
		maintain(x,qv);
		pushup(fa);
		pushup(t[fa].fa);
	}
	void rev(int l,int r)
	{
		int x,fa;
		x=split(l,r);
		fa=t[x].fa;
		t[x].rev^=1;
		swap(t[x].ch[0],t[x].ch[1]);
		swap(t[x].lsum,t[x].rsum);
		pushup(fa);
		pushup(t[fa].fa);
	}
	type ask_sum(int l,int r)
	{
		int x=split(l,r);
		return t[x].sum;
	}
	type ask_max_sum(int l,int r)
	{
		int x=split(l,r);
		return t[x].mxsum;
	}
	type get_val(int x)
	{
		find(x);
		return t[root].v;
	}
	vector<type> res;
	void dfs(int id)
	{
		if(!id) return;
		pushdown(id);
		dfs(t[id].ch[0]);
		res.push_back(t[id].v);
		dfs(t[id].ch[1]);
	}
	void debug()
	{
		res.clear();
		dfs(root);
		puts("************");
		for(int i=0;i<res.size();i++) cout<<res[i]<<" \n"[i==res.size()-1];
		puts("************");
	}
	int size(){return t[root].sz-2;}
	#undef type
}tr; //tr.init();
int main()
{
	int n,q,i,l,r,tot,c;
	char op[12];
	scanf("%d%d",&n,&q);
	vector<ll> a(n);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	tr.init();
	tr.insert(0,a);
//	tr.debug();
	while(q--)
	{
		scanf("%s",op);
		if(op[0]=='I')
		{
			scanf("%d%d",&l,&tot);
			if(tot==0) continue;
			vector<ll> b(tot);
			for(i=0;i<tot;i++) scanf("%lld",&b[i]);
			tr.insert(l,b);
		}
		else if(op[0]=='D')
		{
			scanf("%d%d",&l,&tot);
			if(tot==0) continue;
			r=l+tot-1;
			tr.erase(l,r);
		}
		else if(op[0]=='M' && op[2]=='K')
		{
			scanf("%d%d%d",&l,&tot,&c);
			if(tot==0) continue;
			r=l+tot-1;
			tr.upd(l,r,c);
		}
		else if(op[0]=='R')
		{
			scanf("%d%d",&l,&tot);
			if(tot==0) continue;
			r=l+tot-1;
			tr.rev(l,r);
		}
		else if(op[0]=='G' && op[3]=='-')
		{
			scanf("%d%d",&l,&tot);
			if(tot==0)
			{
				puts("0");
				continue;
			}
			r=l+tot-1;
			printf("%lld\n",tr.ask_sum(l,r));
		}
		else if(op[0]=='G' && op[3]=='\0')
		{
			scanf("%d",&l);
			printf("%d\n",tr.get_val(l));
		}
		else
		{
			scanf("%d%d",&l,&tot);
			if(tot==0)
			{
				puts("0");
				continue;
			}
			r=l+tot-1;
			printf("%lld\n",tr.ask_max_sum(l,r));
		}
	//	tr.debug();
	}
	return 0;
}

