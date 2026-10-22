#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX];
	const int LOG=log2(MAX)+1;
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
	#undef type
}tr;
const int V=1e4+1;
const int D=5001;
struct node{int pos,l,r;};
int main()
{
	int n,i,j,k,a,b,c,d,t;
	ll ans;
	scanf("%d",&n);
	vector<node> x,y,del;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>c || b>d)
		{
			swap(a,c);
			swap(b,d);
		}
		if(a==c) x.push_back({a,b,d});
		else y.push_back({b,a,c});
	}
	sort(y.begin(),y.end(),[](node a,node b){
		return a.pos<b.pos;
	});
	sort(x.begin(),x.end(),[](node a,node b){
		return a.r<b.r;
	});
	ans=0;
	for(i=0;i<y.size();i++)
	{
		tr.init(V);
		del.clear();
		for(auto &it:x)
		{
			if(y[i].pos<it.l || y[i].pos>it.r) continue;
			if(it.pos<y[i].l || it.pos>y[i].r) continue;
			del.push_back(it);
			tr.upd(it.pos+D,1);
		}
		for(j=i+1,k=0;j<y.size();j++)
		{
			while(k<del.size() && del[k].r<y[j].pos)
			{
				tr.upd(del[k].pos+D,-1);
				k++;
			}
			t=tr.ask(y[j].l+D,y[j].r+D);
			ans+=t*(t-1)/2;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
考虑 O(n^2) 级别的做法。
从左到右枚举一条竖线。
先枚举所有横线，将与该竖线相交的横线全部添加进树状数组。
接着枚举第二条竖线，双指针将一些范围外的横线删除。
然后树状数组区间查询即可。复杂度O(n^2 log n)。
*/
