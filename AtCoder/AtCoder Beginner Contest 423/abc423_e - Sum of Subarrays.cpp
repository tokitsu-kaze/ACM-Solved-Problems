#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX];
ll s0[MAX],s1[MAX],s2[MAX];
int main()
{
	int n,q,i,l,r;
	ll sum0,sum1,sum2;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	s0[0]=s1[0]=s2[0]=0;
	for(i=1;i<=n;i++)
	{
		s0[i]=s0[i-1]+a[i];
		s1[i]=s1[i-1]+1LL*a[i]*i;
		s2[i]=s2[i-1]+1LL*a[i]*i*i;
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		sum0=s0[r]-s0[l-1];
		sum1=s1[r]-s1[l-1];
		sum2=s2[r]-s2[l-1];
		printf("%lld\n",(r-l+1-1LL*l*r)*sum0+(l+r)*sum1-sum2);
	}
	return 0;
}
