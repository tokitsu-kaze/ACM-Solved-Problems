#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <list> 
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0) 
using namespace std;
typedef long long ll;
ll mutiply2(ll a,ll b,ll mod)
{
	ll ans=0;
	a%=mod;
	while(b)
	{
		if(b&1)
		{
			ans+=a;
			if(ans>=mod) ans-=mod;
		}
		a<<=1;
		if(a>=mod) a-=mod;
		b>>=1;
	}
	return ans;
}
ll pow2(ll a,ll b,ll mod)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=mutiply2(ans,a,mod);
		} 
		a=mutiply2(a,a,mod);
		b>>=1;
	}
	return ans;
}
int main()  
{
	ll a,b,c;
	while(~scanf("%I64d%I64d%I64d",&a,&b,&c))
	{	
		printf("%I64d\n",pow2(a,b,c));
    }
    return 0;  
}  