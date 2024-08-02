#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e6+10;
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
struct qnode{int l,r,id;};
vector<qnode> qst[MAX];
vector<int> pos[MAX];
int ans[MAX];
int main()
{
	int n,m,i,l,r,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<MAX;i++)
	{
		qst[i].clear();
		pos[i].clear();
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		pos[x].push_back(i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&x);
		qst[x].push_back({l,r,i});
	}
	tr.init(n);
	for(i=1;i<MAX;i++)
	{
		for(auto &it:pos[i]) tr.upd(it,1);
		for(auto &it:qst[i]) ans[it.id]=tr.ask(it.l,it.r);
	}
	for(i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
