#include<bits/stdc++.h>
using namespace std;
//long long arr[200000000];
const long long mod= 1000000007LL;
long long  pmod(long long  a, long long b)
{
	long long  ret = 1;
	long long tmp = a;
	while (b)
	{
		if (b & 0x1) ret = ret*tmp%mod;
		tmp = tmp*tmp%mod;
		b >>= 1;
	}
	return ret;
}
long long n,m;
vector<long long>v;
int main()
{
	/*arr[0]=0;
	arr[1]=2;
	for(int i=2;i<=1e8;i++)
	{
		arr[i]=(3*arr[i-1]-arr[i-2])/2+i+1;
	}
	for(int i=1;i<=100;i++)
	{
		cout<<arr[i]<<" ";
	}*/
	long long inv2=pmod(2,mod-2);
	long long inv6=pmod(6,mod-2);
	while(scanf("%lld%lld",&n,&m)!=EOF)
	{
		v.clear();
		long long m2=m;
		long long sqrtM=sqrt(m+0.5);
		for(long long i=2;i<=sqrtM;i++)
		{
			if(m2%i==0)
			{
				v.push_back(i);
				while(m2%i==0)
					m2/=i;
			}
		}
		if(m2!=1)
			v.push_back(m2);
		int num=v.size();
		long long ans=0;
		for(int i=0;i<(1<<v.size());i++)
		{
			int cnt=0;
			long long d=1;
			for(int j=0;j<v.size();j++)
			{
				if(i & (1<<j))
				{
					cnt++;
					d=d*v[j];
				}
			}
			long long M=n/d;
			long long temp=(d*(1+M)%mod*M%mod*inv2%mod+d*d%mod*M%mod*(M+1)%mod*(2*M+1)%mod*inv6%mod)%mod;
			if(cnt%2==0)
			{
				ans = (ans + temp)%mod;
			}
			else
			{
				ans = (ans - temp +mod)%mod;
			}
		}
		printf("%lld\n",ans);

	}

	return 0;
}