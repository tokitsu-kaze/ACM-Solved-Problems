#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
struct node{int l,r;};
vector<int> posl[MAX],posr[MAX];
int main()
{
	int n,m,q,i,l,r;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		posl[i].clear();
		posr[i].clear();
	}
	map<pair<int,int>,int> mp;
	vector<node> res;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		posl[l].push_back(r);
		posr[r].push_back(l);
		res.push_back({l,r});
		mp[{l,r}]=0;
	}
	sort(res.begin(),res.end(),[](node x,node y){
		if(x.r==y.r) return x.l>y.l;
		return x.r<y.r;
	});
	tr.init(n);
	for(auto &it:res)
	{
		if(tr.ask(it.l,it.r)) mp[{it.l,it.r}]=1;
		tr.upd(it.l,1);
	}
	for(i=1;i<=n;i++)
	{
		sort(posl[i].begin(),posl[i].end());
		sort(posr[i].begin(),posr[i].end());
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		if(mp.count({l,r}))
		{
			if(mp[{l,r}]) puts("Yes");
			else puts("No");
			continue;
		}
		if(posl[l].size()==0 || posr[r].size()==0)
		{
			puts("No");
			continue;
		}
		auto mn=lower_bound(posr[r].begin(),posr[r].end(),l);
		auto mx=upper_bound(posl[l].begin(),posl[l].end(),r);
		if(mn==posr[r].end() || mx==posl[l].begin())
		{
			puts("No");
			continue;
		}
		mx--;
//		printf("%d %d\n",*mx,*mn);
		if(*mx+1>=*mn) puts("Yes");
		else puts("No");
	}
	return 0;
}
