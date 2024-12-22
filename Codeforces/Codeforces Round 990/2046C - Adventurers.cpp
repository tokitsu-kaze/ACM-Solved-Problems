#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Treap
{
	#define type int
	static const type inf=INF;
	struct node
	{
		int ch[2],fix,sz,cnt;
		type v;
		node(){}
		node(type x,int _sz)
		{
			v=x;
			fix=rand();
			sz=cnt=_sz;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];
	int tot,root[MAX],rt;
	void init(int n=1)
	{
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
		srand(time(0));
		tot=0;
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
	void _insert(int &id,type v,int cnt)
	{
		if(!id)
		{
			id=++tot;
			t[id]=node(v,cnt);
			return;
		}
		if(t[id].v==v) t[id].cnt+=cnt;
		else
		{
			int tmp=(v>t[id].v);
			_insert(t[id].ch[tmp],v,cnt);
			if(t[t[id].ch[tmp]].fix>t[id].fix) rotate(id,tmp^1);
		}
		pushup(id);
	}
	void _erase(int &id,type v,int cnt)
	{
		if(!id) return;
		if(t[id].v==v)
		{
			cnt=min(t[id].cnt,cnt);
			if(t[id].cnt>cnt)
			{
				t[id].cnt-=cnt;
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
				_erase(t[id].ch[tmp],v,cnt);
				pushup(id);
			}
		}
		else
		{
			_erase(t[id].ch[v>t[id].v],v,cnt);
			pushup(id);
		}
	}
	int _find(type key,int f)
	{
		int id=root[rt],res=0;
		while(id)
		{
			if(t[id].v<=key)
			{
				res+=t[t[id].ch[0]].sz+t[id].cnt;
				if(f&&key==t[id].v) res-=t[id].cnt;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_by_order(int k)//k small
	{
		int id=root[rt];
		if(id==0) return inf;
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
		return inf;
	}
	int count(type key)
	{
		int id=root[rt];
		while(id)
		{
			if(t[id].v<key)
			{
				if(key==t[id].v) return t[id].cnt;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return 0;
	}
	type find_pre(type key)
	{
		type res=-inf;
		int id=root[rt];
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
		int id=root[rt];
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
	Treap &operator[](const int _rt){this->rt=_rt;return *this;}
	void insert(type v,int sz=1){_insert(root[rt],v,sz);}
	void erase(type v,int sz=1){_erase(root[rt],v,sz);}
	int upper_bound_count(type key){return _find(key,0);}//the count <=key
	int lower_bound_count(type key){return _find(key,1);}//the count <key
	int order_of_key(type key){return lower_bound_count(key)+1;}
	int size(){return t[root[rt]].sz;}
	#undef type
}trpre,trsuf;
/*
1 treap
tr.init();
tr.insert(x);
tr.erase(x);
tr.count(x);
tr.order_of_key(x); // rank
tr.find_by_order(k); // kth
tr.find_pre(x);
tr.find_nex(x);
tr.upper_bound_count(x); //the count <=key
tr.lower_bound_count(x); //the count <key

n treap
tr.init(n);
tr[i].insert(x);
*/
struct node{int x,y;}a[MAX];
const int limt=1e9;
int n,rx,ry;
int ck(int x)
{
	int i,j,prey,sufy,cntpre,cntsuf,mxy;
	trpre.init();
	trsuf.init();
	for(i=1;i<=n;i++) trsuf.insert(a[i].y);
	for(i=1,j=1;i<=n;)
	{
		if(a[i].x==limt) return 0;
		while(j<=n && a[i].x==a[j].x)
		{
			trpre.insert(a[j].y);
			trsuf.erase(a[j].y);
			j++;
		}
		rx=a[i].x+1;
		i=j;
		prey=trpre.find_by_order(x);
		sufy=trsuf.find_by_order(x);
		mxy=max(prey,sufy);
		if(mxy==INF) continue;
		mxy++;
		if(mxy>limt) continue;
		cntpre=trpre.lower_bound_count(mxy);
		cntsuf=trsuf.lower_bound_count(mxy);
		if(cntpre<x || cntsuf<x) continue;
		if(trpre.size()-cntpre<x || trsuf.size()-cntsuf<x) continue;
		ry=mxy;
		return 1;
	}
	return 0;
}
int main()
{
	int T,i,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		sort(a+1,a+1+n,[](node a,node b){
			return a.x<b.x;
		});
		l=0;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
		rx=ry=0;
		ck(l);
		printf("%d %d\n",rx,ry);
	}
	return 0;
}
/*
1
4
-1000000000 -1000000000
1000000000 -1000000000
-1000000000 1000000000
1000000000 1000000000
*/
