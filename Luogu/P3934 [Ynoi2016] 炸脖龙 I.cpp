#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
const int N=2e7+10;
int p[N],phi[N],tot,prime[N];
void init_phi(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=phi[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i])
		{
			prime[i]=p[tot++]=i;
			phi[i]=i-1;
		}
		for(j=0;i*p[j]<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}
struct Fenwick_Tree
{
	#define type ll
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
ll qpow(ll a,ll b,ll p)
{
	if(p==1) return 0;
	ll res=1;
	if(a>=p) a=a%p+p;
	while(b>0)
	{
		if(b&1) res*=a;
		a*=a;
		b>>=1;
		if(res>=p) res=res%p+p;
		if(a>=p) a=a%p+p;
	}
	return res;
}
ll w[MAX];
ll gao(int x,int r,int p)
{
	ll now=w[x]+tr.ask(1,x);
	if(x==r||p==1) return now<p?now:now%p+p;
	return qpow(now,gao(x+1,r,phi[p]),p);
}
int main()
{
	init_phi(N-10);
	int n,m,i,op,l,r,p;
	ll x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld",&w[i]);
	tr.init(n);
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%lld",&x);
			tr.upd(l,x);
			tr.upd(r+1,-x);
		}
		else
		{
			scanf("%d",&p);
			printf("%lld\n",gao(l,r,p)%p);
		}
	}
	return 0;
}
