#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
const int INF=0x3f3f3f3f;
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
}dx,dy;
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
vector<int> res[MAX];
int x[MAX],y[MAX],xmn[MAX],ymn[MAX],xmx[MAX],ymx[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	dx.init();
	dy.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		dx.add(x[i]);
		dy.add(y[i]);
		xmn[i]=ymn[i]=INF;
		xmx[i]=ymx[i]=-INF;
		res[i].clear();
	}
	dx.work();
	dy.work();
	for(i=1;i<=n;i++)
	{
		x[i]=dx.get_pos(x[i]);
		y[i]=dy.get_pos(y[i]);
		xmn[x[i]]=min(xmn[x[i]],y[i]);
		xmx[x[i]]=max(xmx[x[i]],y[i]);
		ymn[y[i]]=min(ymn[y[i]],x[i]);
		ymx[y[i]]=max(ymx[y[i]],x[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(ymn[i]<=ymx[i])
		{
			res[ymn[i]].push_back(i);
			res[ymx[i]+1].push_back(-i);
		}
	}
	tr.init(n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(auto &it:res[i])
		{
			if(it<0) tr.upd(-it,-1);
			else tr.upd(it,1);
		}
		if(xmn[i]<=xmx[i]) ans+=tr.ask(xmn[i],xmx[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
