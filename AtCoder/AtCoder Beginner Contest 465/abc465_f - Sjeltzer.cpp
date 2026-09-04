#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int V=1e7;
const int MAX=V+10;
ll dp[MAX];
int sd[8]={1,10,100,1000,10000,100000,1000000,10000000};
int tx[11],ty[11];
int main()
{
	int n,s,v,i,j,q,x,y,now,sgn,ok;
	ll ans;
	scanf("%d",&n);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&s,&v);
		dp[s]+=v;
	}
	for(j=0;j<7;j++)
	{
		for(i=0;i<=V;i++)
		{
			if(i%sd[j+1]>=sd[j]) dp[i]+=dp[i-sd[j]];
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		ok=1;
		for(j=0;j<7;j++)
		{
			if(x%10>y%10)
			{
				ok=0;
				break;
			}
			tx[j]=(x%10)*sd[j];
			ty[j]=(y%10)*sd[j];
			x/=10;
			y/=10;
		}
		if(!ok)
		{
			puts("0");
			continue;
		}
		ans=0;
		for(i=0;i<(1<<7);i++)
		{
			sgn=1;
			now=0;
			for(j=0;j<7;j++)
			{
				if(!((i>>j)&1)) now+=ty[j];
				else
				{
					sgn*=-1;
					if(tx[j]-sd[j]<0)
					{
						now=-1;
						break;
					}
					now+=tx[j]-sd[j];
				}
			}
			if(now>=0) ans+=sgn*dp[now];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
