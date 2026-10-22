#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
	#define type int
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
	#undef type
}tr;
struct node{int s,t;}a[MAX];
int main()
{
	int n,i,pos;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i].s);
	for(i=1;i<=n;i++) scanf("%d",&a[i].t);
	d.init();
	for(i=1;i<=n;i++) d.add(a[i].t);
	d.work();
	sort(a+1,a+1+n,[](node x,node y){
		return x.s<y.s;
	});
	tr.init(n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		pos=d.get_pos(a[i].t);
		ans+=abs((a[i].s-i)-(a[i].t-pos));
		if(pos<n) ans+=tr.ask(pos+1,n);
		tr.upd(pos,1);
	}
	printf("%lld\n",ans);
	return 0;
}
