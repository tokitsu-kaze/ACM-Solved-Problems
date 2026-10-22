#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
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
	type bit[MAX],tmp[MAX];
	const int LOG=log2(MAX)+1;
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
}tr;
mt19937 rd(time(0));
int n,q,op[MAX],l[MAX],r[MAX],k[MAX],pos[MAX],v[MAX],ta[MAX];
int a[MAX],ans[MAX];
ll ha[2*MAX],tmp[MAX];
const int LIMT=25;
void work()
{
	int i;
	for(i=0;i<=d.size();i++) ha[i]=rd();
	for(i=1;i<=n;i++)
	{
		a[i]=ta[i];
		tmp[i]=ha[a[i]];
	}
	tr.init(n,tmp);
	for(i=1;i<=q;i++)
	{
		if(op[i]==1)
		{
			tr.upd(pos[i],-ha[a[pos[i]]]);
			a[pos[i]]=v[i];
			tr.upd(pos[i],ha[a[pos[i]]]);
		}
		else
		{
			if(tr.ask(l[i],r[i])%k[i]) ans[i]=0;
		}
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&q);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&ta[i]);
		d.add(ta[i]);
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d",&op[i]);
		if(op[i]==1)
		{
			scanf("%d%d",&pos[i],&v[i]);
			d.add(v[i]);
		}
		else scanf("%d%d%d",&l[i],&r[i],&k[i]);
		ans[i]=1;
	}
	d.work();
	for(i=1;i<=n;i++) ta[i]=d.get_pos(ta[i]);
	for(i=1;i<=q;i++)
	{
		if(op[i]==1) v[i]=d.get_pos(v[i]);
	}
	for(i=0;i<LIMT;i++) work();
	for(i=1;i<=q;i++)
	{
		if(op[i]!=2) continue;
		if(ans[i]) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
把每种数映射成随机值，再判断区间 sum%k=0。
但在 k 小的时候，很容易出问题，比如 k=2。
所以需要多做几次。
*/
