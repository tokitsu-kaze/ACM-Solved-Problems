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
int a[MAX],n;
set<int> s;
int ask()
{
	if(n&1)
	{
		if(a[n]==1) return 1;
	}
	if(s.size()==0) return 0;
	int x=*s.rbegin();
	if(tr.ask(x+1,n)==(n-x+1)/2) return 1;
	return 0;
}
int main()
{
	int T,q,i,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		tr.init(n);
		s.clear();
		for(i=2;i<=n;i+=2)
		{
			if(a[i-1]==a[i] && a[i]==1) s.insert(i-1);
			tr.upd(i,a[i]);
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&x,&y);
			if(a[x]==y)
			{
				printf("%d\n",ask());
				continue;
			}
			if(!(x&1)) tr.upd(x,-a[x]);
			if(x&1) s.erase(x);
			else s.erase(x-1);
			a[x]=y;
			if(!(x&1)) tr.upd(x,a[x]);
			if(x&1)
			{
				if(x+1<=n && a[x]==1 && a[x+1]==1) s.insert(x);
			}
			else
			{
				if(x-1>=1 && a[x-1]==1 && a[x]==1) s.insert(x-1);
			}
			printf("%d\n",ask());
		}
	}
	return 0;
}
/*
1. n is odd, and a[n]=1
2. x is odd, last a[x]=a[x+1]=1, and after all a[x+3]=a[x+5]=...=1
*/

/*
int work(int _n)
{
	int i;
	n=_n;
	tr.init(n);
	s.clear();
	for(i=2;i<=n;i+=2)
	{
		if(a[i-1]==a[i] && a[i]==1) s.insert(i-1);
		tr.upd(i,a[i]);
	}
	return ask();
}
int bf(int _n)
{
	int i;
	n=_n;
	int res=a[1];
	for(i=2;i<=n;i++)
	{
		if(i&1) res|=a[i];
		else res&=a[i];
	}
	return res;
}
int main()
{
	srand(time(0));
	int i,cas=0;
	while(1)
	{
		n=1;
		for(i=1;i<=n;i++) a[i]=rand()%2;
		if(work(n)!=bf(n))
		{
			printf("%d\n",n);
			for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
			return 0;
		}
		cas++;
		printf("ok,cas=%d\n",cas);
	}
	return 0;
}
*/
