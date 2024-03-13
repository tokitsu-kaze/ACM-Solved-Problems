#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=20+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			a[i]+=a[i-1];
			bit[i]=a[i]-a[i-lowbit(i)];
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
ll fac[MAX];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
}
int flag[MAX];
int main()
{
	int n,q,i,j,x;
	ll ans,k;
	char op[2];
	init(MAX-10);
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%s",op);
		if(op[0]=='P')
		{
			scanf("%lld",&k);
			k--;
			for(i=1;i<=n;i++) flag[i]=0;
			for(i=1;i<=n;i++)
			{
				x=k/fac[n-i];
				k%=fac[n-i];
				for(j=1;j<=n;j++)
				{
					if(flag[j]) continue;
					if(x==0)
					{
						printf("%d%c",j," \n"[i==n]);
						flag[j]=1;
						break;
					}
					x--;
				}
			}
		}
		else
		{
			tr.init(n);
			ans=1;
			for(i=1;i<=n;i++)
			{
				scanf("%d",&x);
				tr.upd(x,1);
				ans+=1ll*fac[n-i]*(x-tr.ask(1,x));
			}
			printf("%lld\n",ans);
		}
	}	
	return 0;
}
