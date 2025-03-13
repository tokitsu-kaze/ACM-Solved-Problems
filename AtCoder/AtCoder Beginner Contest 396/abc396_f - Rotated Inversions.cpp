#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
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
vector<int> pos[MAX];
int a[MAX];
int main()
{
	int n,m,i,j;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++) pos[i].clear();
	tr.init(m);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=tr.ask(a[i]+2,m);
		tr.upd(a[i]+1,1);
		pos[a[i]].push_back(i);
	}
	for(i=m-1;~i;i--)
	{
		printf("%lld\n",ans);
		for(j=0;j<pos[i].size();j++)
		{
			ans+=pos[i][j]-j-1;
			ans-=(n-pos[i][j])-((int)pos[i].size()-j-1);
		}
	}
	return 0;
}
