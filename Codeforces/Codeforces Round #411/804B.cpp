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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
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
	ll len,i,j,a,b,cnt,mod=1000000000+7,t,temp,t1;
	char c[MAX];
	while(~scanf("%s",c))
	{
		len=strlen(c);
		cnt=t=temp=0;
		a=0;
		for(i=0;i<len;i++)
		{
			if(c[i]=='a')
			{
				a++;
			}
			else if(c[i]=='b')
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
		printf("%I64d\n",cnt%mod);
	}
	return 0;
}
//aaab 7