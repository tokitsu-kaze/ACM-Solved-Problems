#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return upper_bound(all(a),x)-a.begin();} // <= x
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX];
	const int LOG=log2(MAX)+1;
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) res=max(res,bit[x]);
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=max(bit[x],v);
	}
	type ask_max(int r)
	{
		return get(r);
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}tr;
struct node{int x,y,v;};
int main()
{
	int n,m,k,i,x,y,v;
	ll dp,ans;
	scanf("%d%d%d",&n,&m,&k);
	vector<node> res;
	d.init();
	d.add(1);
	d.add(m);
	for(i=1;i<=k;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		res.push_back({x,y,v});
		d.add(y);
	}
	d.work();
	sort(res.begin(),res.end(),[](node a,node b){
		if(a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	});
	tr.init(d.size());
	ans=0;
	for(auto &it:res)
	{
		it.y=d.get_pos(it.y);
		dp=tr.ask_max(it.y)+it.v;
		tr.upd(it.y,dp);
		ans=max(ans,dp);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
给定网格图上的点，求一条最大的权值的不下降的路径，输出一下最大权值
*/
