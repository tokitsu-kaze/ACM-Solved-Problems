#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
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
	type bit[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			a[i]+=a[i-1];
			bit[i]=a[i]-a[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
struct node{int l,r;};
int main()
{
	int t,n,i,j,l,r;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<node> res;
		d.init();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&l,&r);
			res.push_back({l,r});
			d.add(l);
			d.add(r);
		}
		sort(res.begin(),res.end(),[&](node x,node y){
			return x.r<y.r;
		});
		d.work();
		tr.init(d.size());
		ans=0;
		for(auto &it:res)
		{
			ans+=tr.ask(d.get_pos(it.l),d.get_pos(it.r));
			tr.upd(d.get_pos(it.l),1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

