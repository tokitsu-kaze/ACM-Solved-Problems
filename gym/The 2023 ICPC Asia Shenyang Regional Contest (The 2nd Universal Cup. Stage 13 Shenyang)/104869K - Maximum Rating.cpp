#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	#define type ll
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
}tr,trcnt;
int a[MAX],x[MAX],v[MAX];
int main()
{
	int n,q,i,l,r,mid,cnt,pos,val;
	ll negsum,now,res;
	scanf("%d%d",&n,&q);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d.add(a[i]);
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&x[i],&v[i]);
		d.add(v[i]);
	}
	d.work();
	tr.init(d.size());
	trcnt.init(d.size());
	negsum=cnt=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>0)
		{
			pos=d.get_pos(a[i]);
			tr.upd(pos,a[i]);
			trcnt.upd(pos,1);
			cnt++;
		}
		else negsum+=a[i];
	}
	for(i=1;i<=q;i++)
	{
		if(a[x[i]]>0)
		{
			pos=d.get_pos(a[x[i]]);
			tr.upd(pos,-a[x[i]]);
			trcnt.upd(pos,-1);
			cnt--;
		}
		else negsum-=a[x[i]];
		a[x[i]]=v[i];
		if(a[x[i]]>0)
		{
			pos=d.get_pos(a[x[i]]);
			tr.upd(pos,a[x[i]]);
			trcnt.upd(pos,1);
			cnt++;
		}
		else negsum+=a[x[i]];
		l=1;
		r=d.size();
		while(l<r)
		{
			mid=(l+r)>>1;
			if(tr.ask(1,mid)>-negsum) r=mid;
			else l=mid+1;
		}
		res=tr.ask(1,l);
		if(res>0 && res<=-negsum) printf("%d\n",cnt-(cnt-trcnt.ask(1,l))+1);
		else if(res>0)
		{
			now=tr.ask(1,l-1);
			val=d.get_val(l);
//			printf("%lld %d\n",now,val);
			printf("%d\n",cnt-(cnt-trcnt.ask(1,l-1)-(-negsum-now)/val)+1);
		}
		else puts("1");
	}
	return 0;
}
/*
4 1
1 1 1 -2
1 1
*/
