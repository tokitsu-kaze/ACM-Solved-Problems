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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
//typedef long long ll;
typedef unsigned __int64 ll;
ll mul2(ll a,ll b,ll c)
{
	ll ans=0;
	while(b)
	{
		if(b&1) ans=(ans+a)%c;
		b>>=1;
		a=(a+a)%c;
	}
	return ans;
}
ll pow2(ll a,ll b,ll c)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=mul2(ans,a,c);
		b>>=1;
		a=mul2(a,a,c);
	}
	return ans;
}
int main()
{
    ll a,b,c;
    while(cin>>a>>b>>c)
    {
		cout<<pow2(a,b,c)<<endl;
	}
    return 0;
}