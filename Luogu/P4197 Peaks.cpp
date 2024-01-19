#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct Discretization
{
	#define type int
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct Persistent_Segment_Tree
{
	#define type int
	int root[MAX],ls[MAX<<5],rs[MAX<<5],tot,ql,qr,n;
	type v[MAX<<5],qv,res;
	void init(int _n)
	{
		n=_n;
		root[0]=0;
		ls[0]=rs[0]=v[0]=tot=0;
	}
	int copy_node(int x)
	{
		tot++;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		v[tot]=v[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		v[id]+=qv;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]=0,ls[pre]);
		else update(mid+1,r,rs[id]=0,rs[pre]);
	}
	void query_valsum(int l,int r,int id,int pre)
	{
		if(!id) return;
		if(l>=ql&&r<=qr)
		{
			res+=v[id]-v[pre];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query_valsum(l,mid,ls[id],ls[pre]);
		if(qr>mid) query_valsum(mid+1,r,rs[id],rs[pre]);
	}
	int kth_small(int l,int r,int id,int pre,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int tmp=v[ls[id]]-v[ls[pre]];
		if(tmp>=k) return kth_small(l,mid,ls[id],ls[pre],k);
		else return kth_small(mid+1,r,rs[id],rs[pre],k-tmp);
	}
	void update_ver(int now_ver,int pre_ver,int pos,type v)
	{
		ql=qr=pos;
		qv=v;
		update(1,n,root[now_ver],root[pre_ver]);
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void create_ver(int now_ver,int pre_ver,int pos,type v)
	{
		root[now_ver]=0;
		update_ver(now_ver,pre_ver,pos,v);
	}
	int ask_kth_small(int l,int r,int k)
	{
		return kth_small(1,n,root[r],root[l-1],k);
	}
	type ask_valsum(int pre_ver,int now_ver,int val_l,int val_r)
	{
		ql=val_l;
		qr=val_r;
		res=0;
		query_valsum(1,n,root[now_ver],root[pre_ver-1]);
		return res;
	}
	#undef type
}tr;
/*
tr.init(n);
tr.create_ver(now_ver,pre_ver,pos,v);
tr.copy_ver(now_ver,pre_ver);
tr.ask_kth_small(l,r,k);
tr.ask_valsum(l,r,val_l,val_r);
*/
struct Disjoint_Set_Union
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
struct Kruskal_Tree
{
	#define type int
	#define inf INF
	struct edge{int x,y;type w;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int x,int y,type w){e.push_back({x,y,w});}
	int build_kruskal_tree(int n,vector<int> *mp,type *w)
	{
		int rt,x,y,i;
		for(i=1;i<=2*n-1;i++)
		{
			mp[i].clear();
			w[i]=0;
		}
		dsu.init(2*n-1);
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		rt=n;
		for(auto &it:e)
		{
			x=dsu.find(it.x);
			y=dsu.find(it.y);
			if(x==y) continue;
			rt++;
			w[rt]=it.w;
			mp[rt].push_back(x);
			mp[rt].push_back(y);
			dsu.merge(x,rt);
			dsu.merge(y,rt);
		}
		return rt;
	}
	#undef type
	#undef inf
}krsk;
vector<int> mp[MAX];
int w[MAX],h[MAX];
bool flag[MAX];
const int LOG=log2(MAX);
int fa[MAX][LOG+1],l[MAX],r[MAX],tot,id[MAX];
int bittot[MAX];
void dfs(int x,int pre)
{
	flag[x]=1;
	l[x]=++tot;
	id[tot]=x;
	fa[x][0]=pre;
	for(int i=1;i<=LOG;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
	}
	r[x]=tot;
}
int jump(int x,int target)
{
	for(int i=LOG;~i;i--)
	{
		if(fa[x][i]&&w[fa[x][i]]<=target) x=fa[x][i];
	}
	return x;
}
int main()
{
	int n,m,q,i,a,b,c,v,x,k,rt,tmp;
	scanf("%d%d%d",&n,&m,&q);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		d.add(h[i]);
	}
	d.add(INF);
	d.work();
	for(i=1;i<=n;i++) h[i]=d.get_pos(h[i]);
	krsk.init();
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		krsk.add_edge(a,b,c);
	}
	rt=krsk.build_kruskal_tree(n,mp,w);
	for(i=1;i<=rt;i++) flag[i]=0;
	tot=0;
	memset(fa[0],0,sizeof fa[0]);
	for(i=rt;i;i--)
	{
		if(flag[i]) continue;
		dfs(i,0);
	}
	tr.init(d.size());
	bittot[0]=0;
	for(i=1;i<=2*n-1;i++)
	{
		if(id[i]>n)
		{
			h[id[i]]=d.get_pos(INF);
			bittot[i]=0;
		}
		else bittot[i]=1;
		bittot[i]+=bittot[i-1];
		tr.create_ver(i,i-1,h[id[i]],1);
	}
	while(q--)
	{
		scanf("%d%d%d",&v,&x,&k);
		v=jump(v,x);
		tmp=bittot[r[v]]-bittot[l[v]-1];
		if(tmp-k+1<=0)
		{
			puts("-1");
			continue;
		}
		printf("%d\n",d.get_val(tr.ask_kth_small(l[v],r[v],tmp-k+1)));
	}
	return 0;
}
