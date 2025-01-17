#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=8e5+10;
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
struct node{int a,b;}res[MAX];
int main()
{
	int T,n,k,i,j,cnt;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		d.init();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&res[i].a);
			d.add(res[i].a);
			d.add(res[i].a+1);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&res[i].b);
			d.add(res[i].b);
			d.add(res[i].b+1);
		}
		d.work();
		ans=0;
		sort(res+1,res+1+n,[](node x,node y){
			return x.a<y.a;
		});
		tr.init(4*n);
		for(i=1;i<=n;i++)
		{
			cnt=tr.ask(1,d.get_pos(res[i].a));
			if(i-1-cnt<=k) ans=max(ans,1LL*(n-i+1+i-1-cnt)*res[i].a);
			tr.upd(d.get_pos(res[i].b+1),1);
		}
		sort(res+1,res+1+n,[](node x,node y){
			return x.b<y.b;
		});
		tr.init(4*n);
		for(i=1;i<=n;i++) tr.upd(d.get_pos(res[i].a+1),1);
		for(i=1,j=0;i<=n;i++)
		{
			while(j+1<i && res[i].b!=res[j+1].b) tr.upd(d.get_pos(res[++j].a+1),-1);
			cnt=tr.ask(1,d.get_pos(res[i].b));
			if(cnt<=k) ans=max(ans,1LL*(n-i+1)*res[i].b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
4 1
1 2 3 4
3 3 4 5
*/

