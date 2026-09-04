#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int V=1e6;
const int MAX=V+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	const int LOG=log2(MAX)+1;
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
	int lower_bound_pos(type k) // find first pos that sum{1..pos}>=v
	{
		type now=0;
		int i,pos,nex;
		pos=0;
		for(i=LOG;~i;i--)
		{
			nex=pos+(1<<i);
			if(nex<=n && now+bit[nex]<k)
			{
				now+=bit[nex];
				pos=nex;
			}
		}
		return pos+1;
	}
	int upper_bound_pos(type k) // find first pos that sum{1..pos}>v
	{
		type now=0;
		int i,pos,nex;
		pos=0;
		for(i=LOG;~i;i--)
		{
			nex=pos+(1<<i);
			if(nex<=n && now+bit[nex]<=k)
			{
				now+=bit[nex];
				pos=nex;
			}
		}
		return pos+1;
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}tru,trd;
vector<int> mp[MAX];
int ck(int x)
{
	int i,lu,ru,ld,rd,cntu,cntd;
	tru.init(V);
	trd.init(V);
	cntd=cntu=0;
	for(i=1;i<=V;i++)
	{
		for(auto &it:mp[i])
		{
			trd.upd(it,1);
			cntd++;
		}
	}
	for(i=1;i<=V;i++)
	{
		for(auto &it:mp[i])
		{
			tru.upd(it,1);
			trd.upd(it,-1);
			cntu++;
			cntd--;
		}
		if(cntu>2*x) return 0;
		if(cntd>2*x) continue;
		lu=tru.lower_bound_pos(cntu-x);
		ru=tru.upper_bound_pos(x)-1;
		ld=trd.lower_bound_pos(cntd-x);
		rd=trd.upper_bound_pos(x)-1;
		if(min(ru,rd)-max(lu,ld)+1>0) return 1;
	}
	return 0;
}
int main()
{
	int n,i,x,y,l,r,mid;
	scanf("%d",&n);
	for(i=1;i<=V;i++) mp[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		mp[x].push_back(y);
	}
	l=1;
	r=n;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
/*
将平面上的点划分成4个区域，求min{max{每个区域的点的个数}}。
考虑二分答案。枚举横线从上到下扫，分别求出上下可行区间，看是否有交集。
可以用树状数组上二分求，总复杂度两个log。
*/
