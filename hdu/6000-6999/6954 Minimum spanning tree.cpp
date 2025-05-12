#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e7+10;
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
ll sum[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init_prime(MAX-10);
	int T,n,i,pos;
	ll ans;
	sum[0]=p[0];
	for(i=1;i<tot;i++) sum[i]=sum[i-1]+p[i];
	cin>>T;
	while(T--)
	{
		cin>>n;
		pos=upper_bound(p,p+tot,n)-p-1;
		ans=sum[pos]+1LL*(2+n)*(n-1)/2-4;
		cout<<ans<<"\n";
	}
	return 0;
}

