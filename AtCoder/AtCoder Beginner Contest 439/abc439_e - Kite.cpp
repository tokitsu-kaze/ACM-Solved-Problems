#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e5+10;
struct Discretization
{
	#define type ll
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
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) res=max(bit[x],res);
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=max(bit[x],v);
	}
	type ask_max(int r)
	{
		if(r==0) return 0;
		return get(r);
	}
	#undef type
}tr;
struct node{int x,y;};
int a[MAX],b[MAX];
int main()
{
	int n,i,dp;
	scanf("%d",&n);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		d.add(a[i]);
		d.add(b[i]);
	}
	d.work();
	vector<node> res;
	for(i=1;i<=n;i++)
	{
		res.push_back({d.get_pos(a[i]),d.get_pos(b[i])});
	}
	sort(res.begin(),res.end(),[](node a,node b){
		if(a.x==b.x) return a.y>b.y;
		return a.x<b.x;
	});
	tr.init(d.size());
	for(auto &it:res)
	{
		dp=tr.ask_max(it.y-1)+1;
		tr.upd(it.y,dp);
	}
	printf("%d\n",tr.ask_max(d.size()));
	return 0;
}
