#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
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
struct node{int x,y,c;};
int main()
{
	int n,m,i,x,y,ok;
	char op[2];
	scanf("%d%d",&n,&m);
	vector<node> res;
	d.init();
	while(m--)
	{
		scanf("%d%d%s",&x,&y,op);
		if(op[0]=='B') res.push_back({x,y,0});
		else res.push_back({x,y,1});
		d.add(x);
		d.add(y);
	}
	d.work();
	sort(res.begin(),res.end(),[](node a,node b){
		if(a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	});
	tr.init(d.size());
	ok=1;
	for(auto &it:res)
	{
		if(it.c==1) tr.upd(d.get_pos(it.y),1);
		else
		{
			if(tr.ask(1,d.get_pos(it.y))) ok=0;
		}
//		printf("%d %d %d\n",it.x,it.y,ok);
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}

