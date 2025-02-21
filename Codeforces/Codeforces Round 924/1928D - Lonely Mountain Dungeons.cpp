#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=1e9+7;
const int MAX=2e5+10;
int c[MAX];
ll sum[MAX],bit[MAX];
void cal(int x,int b)
{
	int i,p;
	ll tmp,mx;
	mx=0;
	p=0;
	for(i=2;i<=x;i++)
	{
		tmp=0;
		tmp+=1LL*(i-x%i)*(x-x/i)*(x/i)*b;
		tmp+=1LL*(x%i)*(x-(x/i+1))*(x/i+1)*b;
		assert(tmp%2==0);
		tmp/=2;
		sum[i]+=tmp;
		if(tmp>mx)
		{
			mx=tmp;
			p=i;
		}
	}
	sum[p]-=mx;
	bit[p]+=mx;
}
int main()
{
	int T,n,b,x,i,j,tot;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&b,&x);
		tot=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			tot+=c[i];
		}
		for(i=1;i<=tot;i++) sum[i]=bit[i]=0;
		for(i=1;i<=n;i++) cal(c[i],b);
		bit[0]=0;
		for(i=1;i<=tot;i++) bit[i]+=bit[i-1];
		ans=0;
		for(i=1;i<=tot;i++) ans=max(ans,sum[i]+bit[i]-1LL*(i-1)*x);
		printf("%lld\n",ans);
	}
	return 0;
}
