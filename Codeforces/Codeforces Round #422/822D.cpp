#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=5e6+10;
const ll mod=1e9+7;
ll prime[MAX];
void init()
{
	ll i,j;
	mem(prime,0);
	prime[0]=prime[1]=1;
	for(i=2;i<=sqrt(MAX);i++)
	{
		if(!prime[i])
		{
			for(j=i+i;j<=MAX;j+=i)
			{
				if(!prime[j]) prime[j]=i;
			}
		}
	}
}
int main()
{
	ll t,l,r,i,t1,t2,temp,ans;
	init();
	while(~scanf("%lld%lld%lld",&t,&l,&r))
	{
		ans=0;
		t1=1;
		for(i=l;i<=r;i++)
		{
			temp=i;
			t2=0;
			while(temp>1)
			{
				if(!prime[temp])
				{
					t2+=(temp*(temp-1))/2;
					t2%=mod;
					break;
				}
				else
				{
					t2+=(prime[temp]*(prime[temp]-1))/2*(temp/prime[temp])%mod;
					temp/=prime[temp];
				}
			}
			ans=(ans+t1*t2%mod)%mod;
			t1=t1*t%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}