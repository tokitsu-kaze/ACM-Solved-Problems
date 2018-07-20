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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=3e5+10;
const ll mod=10000;
ll f(ll x)
{
	ll res=0;
	while(x)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}
int main()
{
	ll t,ans,n,s;
	while(~scanf("%lld%lld",&n,&s))
	{
		ll l,r,mid;
		l=s;
		r=s+162;
		while(r>l)
		{
	//		cout<<l<<" "<<r<<endl;
			mid=(l+r)>>1;
			if(mid-f(mid)<s) l=mid+1;
			else r=mid;
		}
		printf("%lld\n",n-l+1>0?n-l+1:0);
	} 
	return 0;
}
//+10 9
/*
10000 1000
1010 1008 t=112
*/