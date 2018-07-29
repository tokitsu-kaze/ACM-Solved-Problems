#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
using namespace std;
typedef __int64 i64;
i64 mul2(i64 a,i64 b,i64 mod)
{
	i64 ans=0;
	while(b)
	{
		if(b&1)
		{
			ans=(ans+a)%mod;
		}
		a=(a<<1)%mod;
		b>>=1;
	}
	return ans;
}
i64 pow2(i64 a,i64 b,i64 mod)
{
	i64 ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=mul2(ans,a,mod);
		}
		a=mul2(a,a,mod);
		b>>=1;
	}
	return ans;
}
int main()
{
    i64 a,b,mod;
    while(cin>>a>>b>>mod)
    {
		cout<<pow2(a,b,mod)<<endl;
    }
    return 0;
}