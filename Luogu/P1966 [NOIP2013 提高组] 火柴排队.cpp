#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=int(1e8)-3;
const int MAX=1e5+10;
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
int a[MAX],b[MAX],id[MAX];
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d.add(a[i]);
	}
	d.work();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		id[i]=i;
	}
	sort(id+1,id+1+n,[](int x,int y){
		return b[x]<b[y];
	});
	tr.init(n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		x=d.get_pos(a[i]);
		ans+=id[x]-1-tr.ask(1,id[x]);
		tr.upd(id[x],1);
	}
	printf("%lld\n",ans%mod);
	return 0;
}
