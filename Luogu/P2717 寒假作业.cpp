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
int sum[MAX];
int main()
{
	int n,k,i,x;
	ll ans;
	scanf("%d%d",&n,&k);
	sum[i]=0;
	d.init();
	d.add(0);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum[i]=sum[i-1]+x;
		d.add(sum[i]-i*k);
	}
	d.work();
	tr.init(d.size());
	ans=0;
	tr.upd(d.get_pos(0),1);
	for(i=1;i<=n;i++)
	{
		x=d.get_pos(sum[i]-i*k);
		ans+=tr.ask(1,x);
		tr.upd(x,1);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
(sum[r]-sum[l-1])/r-l+1>=k
(sum[r]-sum[l-1])>=(r-l+1)*k
sum[r]-r*k>=sum[l-1]-(l-1)*k
*/
