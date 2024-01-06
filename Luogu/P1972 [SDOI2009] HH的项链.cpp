#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
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
struct q{int l,id;};
vector<q> qst[MAX];
int a[MAX],ans[MAX],pre[MAX];
int main()
{
	int n,q,i,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		qst[i].clear();
		pre[i]=0;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		qst[r].push_back({l,i});
	}
	tr.init(n);
	for(i=1;i<=n;i++)
	{
		if(pre[a[i]]) tr.upd(pre[a[i]],-1);
		tr.upd(i,1);
		pre[a[i]]=i;
		for(auto &it:qst[i]) ans[it.id]=tr.ask(it.l,i);
	}
	for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
