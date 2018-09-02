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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-5;
const int MAX=1e6+10;
const ll mod=1e9+6;
char c[MAX];
ll pow2(ll a,ll b,ll mod)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	ll len,i,j,a,b,cnt,t,temp,t1,cas;
	scanf("%lld",&cas);
	while(cas--)
	{
		scanf("%s",c);
		len=strlen(c);
		cnt=t=temp=0;
		a=0;
		for(i=0;i<len;i++)
		{
			if(c[i]=='0')
			{
				a++;
			}
			else if(c[i]=='1')
			{
				cnt=(cnt+temp)%mod;
				for(;t<a;t++)
				{
					t1=pow2(2,t,mod);
					temp+=t1;
					cnt+=t1;
					cnt%=mod;
				}
			}
		}
		printf("%lld\n",cnt%mod);
	}
	return 0;
}
//0001 7