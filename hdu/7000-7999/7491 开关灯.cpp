#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace test
{
	int vis[4000005];
	void work()
	{
		int n,i;
		for(n=1;n<=20;n++)
		{
			memset(vis,0,sizeof vis);
			queue<int> q;
			q.push(0);
			vis[0]=1;
			while(!q.empty())
			{
				int t=q.front();
				q.pop();
				for(i=0;i<n;i++)
				{
					int now=t;
					if(i-1>=0) now=now^(1<<(i-1));
					now^=(1<<i);
					if(i+1<n) now=now^(1<<(i+1));
					if(!vis[now])
					{
						vis[now]=1;
						q.push(now);
					}
				}
			}
			int res=0;
			for(i=0;i<(1<<n);i++) res+=vis[i];
			printf("%d %d\n",n,res);
		}
	}
}
const int mod=998244353;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
//	test::work();
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%3==2) printf("%lld\n",qpow(2,n-1));
		else printf("%lld\n",qpow(2,n));
	}
	return 0;
}
