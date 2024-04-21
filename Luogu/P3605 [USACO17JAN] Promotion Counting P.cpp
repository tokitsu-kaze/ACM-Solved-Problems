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
vector<int> mp[MAX];
int ans[MAX],a[MAX];
void dfs(int x)
{
	int p=d.get_pos(a[x]);
	ans[x]=0;
	ans[x]-=tr.ask(p,d.size());
	for(auto &to:mp[x]) dfs(to);
	ans[x]+=tr.ask(p,d.size());
	tr.upd(p,1);
}
int main()
{
	int n,i,x;
	scanf("%d",&n);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d.add(a[i]);
		mp[i].clear();
	}
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		mp[x].push_back(i);
	}
	d.work();
	tr.init(d.size());
	dfs(1);
	for(i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
