#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
struct Fenwick_Tree
{
	#define type ll
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
int a[MAX];
int main()
{
	int n,q,i,op,l,r,x,y,pos;
	ll ans;
	scanf("%d%d",&n,&q);
	tr.init(n);
	set<int> s;
	s.insert(0);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tr.upd(i,a[i]);
		if(a[i]==0) s.insert(i);
	}
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			tr.upd(x,y-a[x]);
			if(a[x]==0) s.erase(x);
			a[x]=y;
			if(a[x]==0) s.insert(x);
		}
		else
		{
			scanf("%d%d%d",&l,&r,&x);
			pos=*--s.upper_bound(r);
			ans=x;
			if(pos>=l) ans=(ans+tr.ask(l,pos))%mod;
			ans+=tr.ask(max(l,pos+1),r);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
