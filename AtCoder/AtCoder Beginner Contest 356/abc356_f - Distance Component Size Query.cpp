#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int op[MAX];
ll x[MAX];
int main()
{
	int q,i;
	ll k,l,r;
	scanf("%d%lld",&q,&k);
	d.init();
	for(i=1;i<=q;i++)
	{
		scanf("%d%lld",&op[i],&x[i]);
		d.add(x[i]);
	}
	d.add(-LLINF);
	d.add(LLINF);
	d.work();
	tr.init(d.size());
	set<ll> s,sk;
	s.insert(-LLINF);
	s.insert(LLINF);
	sk.insert(-LLINF);
	sk.insert(LLINF);
	for(i=1;i<=q;i++)
	{
		if(op[i]==1)
		{
			if(s.count(x[i]))
			{
				s.erase(x[i]);
				sk.erase(x[i]);
				tr.upd(d.get_pos(x[i]),-1);
				auto it=s.lower_bound(x[i]);
				r=*it;
				it--;
				l=*it;
				if(r-l>k) sk.insert(l);
			}
			else
			{
				auto it=s.lower_bound(x[i]);
				r=*it;
				it--;
				l=*it;
				if(r-l>k)
				{
					if(l!=-LLINF) sk.erase(l);
				}
				if(r-x[i]>k) sk.insert(x[i]);
				if(x[i]-l>k) sk.insert(l);
				s.insert(x[i]);
				tr.upd(d.get_pos(x[i]),1);
			}
		}
		else
		{
			auto it=sk.lower_bound(x[i]);
			r=d.get_pos(*it);
			it--;
			l=d.get_pos(*it);
			printf("%d\n",tr.ask(l+1,r));
		}
//		for(auto &it:sk)cout<<it<<" ";
//		puts("");
	}
	return 0;
}

