#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+11;
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
//	printf("%d\n",tot);
}
int a[MAX],b[MAX],id[MAX],vis[MAX],ok;
ll ans;
void work(int x,int v,int ck=0)
{
	int t;
	while(x>1)
	{
		t=prime[x];
		if(vis[t] && v==1) ok=1;
		vis[t]+=v;
		if(ck) ans=min(ans,1LL*b[id[1]]*((t-a[id[1]]%t)%t));
		while(x%t==0) x/=t;
	}
}
int main()
{
	init_prime(MAX-10);
	memset(vis,0,sizeof vis);
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=LLINF;
		ok=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			work(a[i],1);
			id[i]=i;
		}
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		if(ok) ans=0;
		for(i=1;i<=n;i++)
		{
			work(a[i],-1);
			ok=0;
			work(a[i]+1,1);
			if(ok) ans=min(ans,1LL*b[i]);
			work(a[i]+1,-1);
			work(a[i],1);
		}
		sort(id+1,id+1+n,[&](int x,int y){
			return b[x]<b[y];
		});
		ans=min(ans,0LL+b[id[1]]+b[id[2]]);
		work(a[id[1]],-1);
		for(i=2;i<=n;i++) work(a[id[i]],-1,1);
		printf("%lld\n",ans);
	}
	return 0;
}
