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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e6;
ll cal(ll x)
{
	ll i,res=0;;
	for(i=2;i*i*i<=x;i++)
	{
		res+=x/(i*i*i);
	}
	return res;
}
int main()
{
	ll x,l,r,mid,v;
	while(~scanf("%lld",&x))
	{
		l=1;
		r=1e18;
		while(l<r)
		{
			mid=(l+r)/2;
			v=cal(mid);
			if(v<x) l=mid+1;
			else r=mid;
	//		cout<<cal(l)<<" "<<l<<endl;
		}
		if(cal(l)!=x) puts("-1");
		else printf("%lld\n",l);
	}
	return 0;
}