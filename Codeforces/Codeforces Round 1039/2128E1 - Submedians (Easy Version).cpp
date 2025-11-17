#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX<<1],tmp[MAX<<1];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=INF;
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=INF;
		while(x)
		{
			res=min(bit[x],res);
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]=min(bit[x],v);
			x+=lowbit(x);
		}
	}
	#undef type
}tr;
int a[MAX],b[MAX],n,k,x,y;
int ck(int d)
{
	int delta=n+1;
	int i,sum,tmp;
	for(i=1;i<=n;i++)
	{
		if(a[i]<d) b[i]=-1;
		else b[i]=1;
	}
	x=0;
	y=-1;
	sum=0;
	tr.init(delta*2);
	tr.upd(delta,1);
	for(i=1;i<=n;i++)
	{
		sum+=b[i];
		tmp=tr.get(delta+sum);
		if(i-tmp+1>=k)
		{
			x=tmp;
			y=i;
			return 1;
		}
		tr.upd(delta+sum,i+1);
	}
	return 0;
}
int main()
{
	int T,i,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		ck(l);
		printf("%d %d %d\n",l,x,y);
	}
	return 0;
}
