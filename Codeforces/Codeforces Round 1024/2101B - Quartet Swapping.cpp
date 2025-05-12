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
int res[MAX],pos[MAX];
int main()
{
	int T,n,i,x,p1,p2;
	ll ra,rb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		tr.init(n);
		ra=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			pos[x]=i;
			ra+=tr.ask(x,n);
			tr.upd(x,1);
		}
		p1=1;
		p2=2;
		for(i=1;i<=n;i++)
		{
			if(pos[i]&1)
			{
				res[p1]=i;
				p1+=2;
			}
			else
			{
				res[p2]=i;
				p2+=2;
			}
		}
		tr.init(n);
		rb=0;
		for(i=1;i<=n;i++)
		{
			rb+=tr.ask(res[i],n);
			tr.upd(res[i],1);
		}
		if(ra%2!=rb%2) swap(res[n],res[n-2]);
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
/*
1
4
3 2 1 4
*/
