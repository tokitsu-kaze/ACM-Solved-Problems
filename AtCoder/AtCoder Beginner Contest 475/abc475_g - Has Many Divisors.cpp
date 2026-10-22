#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8000+10;
//x is a prime if prime[x]==x(x>=2)
const int V=60;
int p[V+5],tot,prime[V+5];
void init_prime()
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=V;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=V;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int mxlimt[V+5];
ll ans,n,d,mx;
void dfs(int x,ll now,ll cnt,int limt,int f)
{
	int i;
	if(x==tot) return;
	if(now%d==0) return;
	if(mx<cnt)
	{
		mx=cnt;
		ans=now;
	}
//	dfs(x+1,now,cnt,limt,f);
	if(mxlimt[x]>0 && !f)
	{
		dfs(x+1,now,cnt,limt,1);
		for(i=1;i<mxlimt[x];i++)
		{
			if(n/p[x]<now) break;
			now*=p[x];
			dfs(x+1,now,cnt*(i+1),limt,1);
		}
		for(i=mxlimt[x];i<=limt;i++)
		{
			if(n/p[x]<now) break;
			now*=p[x];
			dfs(x+1,now,cnt*(i+1),i,f);
		}
	}
	else
	{
		for(i=1;i<=limt;i++)
		{
			if(n/p[x]<now) break;
			now*=p[x];
			dfs(x+1,now,cnt*(i+1),i,f);
		}
	}
}
int main()
{
	init_prime();
	int T,i;
	ll tmpd;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		memset(mxlimt,0,sizeof mxlimt);
		tmpd=d;
		for(i=0;i<tot;i++)
		{
			while(tmpd%p[i]==0)
			{
				tmpd/=p[i];
				mxlimt[i]++;
			}
		}
		mx=0;
		if(tmpd>1) dfs(0,1,1,60,1);
		else dfs(0,1,1,60,0);
		printf("%lld\n",ans);
	}
	return 0;
}
