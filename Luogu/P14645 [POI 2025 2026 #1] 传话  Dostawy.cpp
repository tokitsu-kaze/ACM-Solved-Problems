#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		tmp[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=a[i];
			tmp[i]+=tmp[i-1];
			bit[i]=tmp[i]-tmp[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) res+=bit[x];
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]+=v;
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}trcnt;
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
		void init(){mx=-inf;}
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
		t[ls].mx+=tag[id];
		t[rs].mx+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
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
			if(qop==1) t[id].mx=qv;
			else
			{
				t[id].mx+=qv;
				tag[id]+=qv;
			}
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
	void upd(int l,int r,type v,int op)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qop=op;
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
struct node{int x,y,d;};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,dis[1010][1010],id[1010][1010];
char mp[1010][1010];
void bfs()
{
	int i;
	node t,nex;
	memset(dis,0x3f,sizeof dis);
	queue<node> q;
	q.push({1,1,0});
	dis[1][1]=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>n) continue;
			if(mp[nex.x][nex.y]=='#') continue;
			if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1;
				q.push(nex);
			}
		}
	}
}
int main()
{
	int q,x,y,i,j;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	bfs();
	vector<node> res;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			res.push_back({i,j,dis[i][j]});
		}
	}
	sort(res.begin(),res.end(),[](node a,node b){
		return a.d>b.d;
	});
	trcnt.init(n*n);
	for(i=0;i<n*n;i++)
	{
		x=res[i].x;
		y=res[i].y;
		id[x][y]=i+1;
		if(mp[x][y]=='Z') tr.a[i+1]=0;
		else if(mp[x][y]=='#'||mp[x][y]=='.') tr.a[i+1]=-tr.inf;
		else
		{
			tr.a[i+1]=trcnt.ask(1,i+1)+res[i].d;
			trcnt.upd(i+1,1);
		}
	}
	tr.build(n*n);
	printf("%d\n",tr.ask(1,n*n));
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(mp[x][y]=='F')
		{
			mp[x][y]='.';
			tr.upd(id[x][y],id[x][y],-tr.inf,1);
			tr.upd(id[x][y],n*n,-1,2);
			trcnt.upd(id[x][y],-1);
		}
		else
		{
			mp[x][y]='F';
			tr.upd(id[x][y],id[x][y],
				trcnt.ask(1,id[x][y])+dis[x][y],1);
			tr.upd(id[x][y]+1,n*n,1,2);
			trcnt.upd(id[x][y],1);
		}
		printf("%d\n",max(0,tr.ask(1,n*n)));
	}
	return 0;
}
