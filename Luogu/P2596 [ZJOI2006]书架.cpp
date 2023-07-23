#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Treap
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int ch[2],fix,sz,cnt;
		type v;
		node(){}
		node(type x)
		{
			v=x;
			fix=rand();
			sz=cnt=1;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];
	int tot,root;
	void init()
	{
		srand(time(0));
		root=tot=0;
		t[0].sz=t[0].cnt=0;
		memset(t[0].ch,0,sizeof t[0].ch);
	}
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ch[0]].sz+t[t[id].ch[1]].sz+t[id].cnt;  
	}  
	void rotate(int &id,int k)
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
		if(t[id].v==v) t[id].cnt++;
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
			if(t[id].cnt>1)
			{
				t[id].cnt--;
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
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k) return t[id].v;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
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
				res+=t[t[id].ch[0]].sz+t[id].cnt;
				if(f&&key==t[id].v) res-=t[id].cnt;
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
	int upper_bound_count(type key){return find(key,0);}//the count <=key
	int lower_bound_count(type key){return find(key,1);}//the count <key
	int rank(type key){return lower_bound_count(key)+1;}
	int size(){return t[root].sz;}
	#undef type
}tr; //tr.init();
const int delta=2e5;
ll id[MAX];
int p[MAX];
int main()
{
	ll now;
	int n,m,i,s,t,x,rk;
	char op[11];
	scanf("%d%d",&n,&m);
	now=0;
	map<ll,int> mp;
	tr.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mp[now]=x;
		id[x]=now;
		tr.insert(now);
		now+=delta;
		p[i]=x;
	}
//	for(i=1;i<=n;i++) printf("%d%c",mp[tr.kth(i)]," \n"[i==n]);
//	for(i=1;i<=n;i++) printf("%d%c",tr.rank(id[i])," \n"[i==n]);
	while(m--)
	{
		scanf("%s%d",op,&s);
		if(op[0]=='T')
		{
			x=mp[tr.kth(1)];
			mp.erase(id[s]);
			tr.erase(id[s]);
			id[s]=id[x]-1;
			mp[id[s]]=s;
			tr.insert(id[s]);
		}
		else if(op[0]=='B')
		{
			x=mp[tr.kth(n)];
			mp.erase(id[s]);
			tr.erase(id[s]);
			id[s]=id[x]+1;
			mp[id[s]]=s;
			tr.insert(id[s]);
		}
		else if(op[0]=='I')
		{
			scanf("%d",&t);
			if(t==0) continue;
			rk=tr.rank(id[s]);
			if(rk+t<1||rk+t>n) continue;
			x=mp[tr.kth(rk+t)];
			mp[id[s]]=x;
			mp[id[x]]=s;
			swap(id[s],id[x]);
		}
		else if(op[0]=='A') printf("%d\n",tr.rank(id[s])-1);
		else printf("%d\n",mp[tr.kth(s)]);
	}
	return 0;
}
/*
5 9
2 1 5 3 4 
Top 3
Insert 2 0
Ask 4
Bottom 2
Insert 5 -1
Bottom 2
Query 3
Ask 4
Ask 5


4
1
3
1
*/
