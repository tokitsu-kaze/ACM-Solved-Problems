#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct Treap
{
	#define type int
	const type inf=INF;
	struct node
	{
		int ch[2],fix,sz,w;
		type v;
		node(){}
		node(type x)
		{
			v=x;
			fix=rand();
			sz=w=1;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];  
	int tot,root;
	void init()
	{
		srand(time(0));
		root=tot=0;
		t[0].sz=t[0].w=0;
		memset(t[0].ch,0,sizeof t[0].ch);
	}
	inline void pushup(int k)  
	{  
		t[k].sz=t[t[k].ch[0]].sz+t[t[k].ch[1]].sz+t[k].w ;  
	}  
	inline void rotate(int &id,int k)
	{
		int y=t[id].ch[k^1];
		t[id].ch[k^1]=t[y].ch[k];
		t[y].ch[k]=id;
		pushup(id);
		pushup(y);
		id=y;
	}
	void insert(int &id,type v)
	{
		if(!id)
		{
			id=++tot;
			t[id]=node(v);
			return;
		}
		if(t[id].v==v) t[id].w++;
		else
		{
			int tmp=(v>t[id].v);
			insert(t[id].ch[tmp],v);
			if(t[t[id].ch[tmp]].fix>t[id].fix) rotate(id,tmp^1);
		}
		pushup(id);
	}
	void erase(int &id,type v)
	{
		if(!id) return;
		if(t[id].v==v)
		{
			if(t[id].w>1)
			{
				t[id].w--;
				pushup(id);
				return;
			}
			if(!(t[id].ch[0]&&t[id].ch[1]))
			{
				id=t[id].ch[0]+t[id].ch[1];
				return;
			}
			else
			{
				int tmp=(t[t[id].ch[0]].fix>t[t[id].ch[1]].fix);
				rotate(id,tmp);
				erase(t[id].ch[tmp],v);
				pushup(id);
			}
		}
		else
		{
			erase(t[id].ch[v>t[id].v],v);
			pushup(id);
		}
	}
	type kth(int k)//k small
	{
		int id=root;
		if(id==0) return 0;
		while(id)
		{
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].w>=k) return t[id].v;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].w;
				id=t[id].ch[1];
			}
		}
	}
	int find(type key,int f)
	{
		int id=root,res=0;
		while(id)
		{
			if(t[id].v<key)
			{
				res+=t[t[id].ch[0]].sz+t[id].w;
				if(f&&key==t[id].v) res-=t[id].w;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_pre(type key)
	{
		type res=-inf;
		int id=root;
		while(id)
		{
			if(t[id].v<key)
			{
				res=t[id].v;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_nex(type key)
	{
		type res=inf;
		int id=root;
		while(id)
		{
			if(t[id].v>key)
			{
				res=t[id].v;
				id=t[id].ch[0];
			}
			else id=t[id].ch[1];
		}
		return res;
	}
	void insert(type v){insert(root,v);}
	void erase(type v){erase(root,v);}
	int upper_bound_count(type key){return find(key,0);}//the count >=key
	int lower_bound_count(type key){return find(key,1);}//the count >key
	int rank(type key){return lower_bound_count(key)+1;}
	int size(){return t[root].sz;}
	#undef type
}tr; //tr.init();
int main()
{
	int n,q,i,op,x;
	scanf("%d%d",&n,&q);
	tr.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		tr.insert(-x);
	}
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1) printf("%d\n",-tr.kth(x));
		else tr.insert(-x);
	}
	return 0;
}
