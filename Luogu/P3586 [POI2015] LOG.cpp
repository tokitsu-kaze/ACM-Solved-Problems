#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e6+10;
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
	#define type ll
	type bit[MAX];
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
}tr,tr2;
char op[MAX][2];
int x[MAX],y[MAX],a[MAX];
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	d.init();
	d.add(0);
	for(i=1;i<=n;i++) a[i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%s%d%d",op[i],&x[i],&y[i]);
		d.add(y[i]);
	}
	d.work();
	n=d.size();
	tr.init(n);
	tr2.init(n);
	for(i=1;i<=m;i++)
	{
		if(op[i][0]=='U')
		{
			tr.upd(d.get_pos(a[x[i]]),-a[x[i]]);
			tr2.upd(d.get_pos(a[x[i]]),-1);
			a[x[i]]=y[i];
			tr.upd(d.get_pos(a[x[i]]),a[x[i]]);
			tr2.upd(d.get_pos(a[x[i]]),1);
		}
		else
		{
			if(tr.ask(1,d.get_pos(y[i])-1)>=
				1ll*y[i]*(x[i]-tr2.ask(d.get_pos(y[i]),n)))
			{
				puts("TAK");
			}
			else puts("NIE");
		}
	}
	return 0;
}
