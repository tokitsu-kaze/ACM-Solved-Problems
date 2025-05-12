#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
//x is a prime if prime[x]==x(x>=2)
const int N=1e7+10;
int p[N],tot,prime[N];
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
int a[MAX];
int main()
{
	init_prime(N-10);
//	printf("%d\n",tot);
	int T,n,i,ans;
	ll sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		reverse(a,a+n);
		sum=0;
		ans=0;
		for(i=0;i<n;i++)
		{
			if(a[i]<p[i])
			{
				sum-=p[i]-a[i];
				if(sum<0)
				{
					ans=n-i;
					break;
				}
			}
			else sum+=a[i]-p[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

