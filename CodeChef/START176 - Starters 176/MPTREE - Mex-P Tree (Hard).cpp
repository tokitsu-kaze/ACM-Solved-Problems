#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init_prime(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
int a[MAX],b[MAX],v[MAX],presz[MAX];
ll res[MAX];
int main()
{
	int T,n,i,pos,sz;
	ll now;
	init_prime(MAX-10);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			res[i]=0;
			presz[i]=0;
			scanf("%d",&v[i]);
		}
		for(i=1;i<n;i++) scanf("%d%d",&a[i],&b[i]);
		now=1;
		pos=0;
		while(pos<tot && now<=1e9) now*=p[pos++];
		dsu.init(n);
		while(pos>=0)
		{
			for(i=1;i<n;i++)
			{
				if(v[a[i]]%now==0 && v[b[i]]%now==0)
				{
					dsu.merge(a[i],b[i]);
				}
			}
			for(i=1;i<=n;i++)
			{
				if(v[i]%now) continue;
				sz=dsu.sz[dsu.find(i)];
				res[i]+=1LL*p[pos]*(sz-presz[i]);
				presz[i]=sz;
			}
			if(pos-1<0) break;
			now/=p[pos-1];
			pos--;
		}
		for(i=1;i<=n;i++) printf("%lld%c",res[i]," \n"[i==n]);
	}
	return 0;
}
