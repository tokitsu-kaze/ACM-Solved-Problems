#include<bits/stdc++.h>
using namespace std;

long long  pmod(long long  a, long long b, long long  n)
{
	long long  ret = 1;
	long long tmp = a;
	while (b)
	{
		if (b & 0x1) ret = ret*tmp%n;
		tmp = tmp*tmp%n;
		b >>= 1;
	}
	return ret;
}
const long long mod=(long long)1e9+7;
int main()
{


	int t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		scanf("%lld%lld",&n,&m);
		if(m==1)
		{
			puts("2");
			continue;
		}
		if(n==1)
        {
            long long ans=pmod(2,m,mod);
            printf("%lld\n",ans);
            continue;
        }
		long long M=pmod(2,m,mod);
		long long ans=pmod(((M-1+mod)%mod),n,mod);
		if(n%2==0)
		{
			ans=((ans+M-1)%mod+mod)%mod;
		}
		else
		{
			ans=((ans+1)%mod+mod)%mod;
		}
		printf("%lld\n",ans);

	}



}