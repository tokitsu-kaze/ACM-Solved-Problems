#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Fenwick_Tree
{
	#define type ll
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
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}trcnt,trv;
int a[MAX],pos[MAX];
int main()
{
	int n,i,mid;
	ll revcnt,lsum,rsum,lcnt,rcnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	revcnt=0;
	trcnt.init(n);
	trv.init(n);
	for(i=1;i<=n;i++)
	{
		revcnt+=trcnt.ask(pos[i],n);
		trcnt.upd(pos[i],1);
		trv.upd(pos[i],pos[i]);
		mid=trcnt.lower_bound_pos((i+1)/2);
		lcnt=(i+1)/2;
		rcnt=i-lcnt;
		lsum=trv.ask(1,mid);
		rsum=trv.ask(mid+1,n);
		printf("%lld%c",revcnt+
			mid*lcnt-lsum-lcnt*(lcnt-1)/2+
			rsum-mid*rcnt-rcnt*(rcnt+1)/2," \n"[i==n]);
	}
	return 0;
}
/*
感觉是脑电波题。得想到分成两部分：先挤在一起，再求排序步数。
挤在一起经典结论就是往中间靠，排序步数其实就是逆序对。
两部分加起来就是答案。
计算挤在一起，先树状数组上二分求出中间的位置，然后算算。
逆序对随便维护一下就行了。
*/
