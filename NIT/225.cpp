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
const int MAX=1e5+10;
const ll mod=1e6;
ll a[MAX],add[MAX];
int main()
{
	ll n,m,i,l,r,x;
	while(~scanf("%lld%lld",&n,&m))
	{
		mem(add,0);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		while(m--)
		{
			scanf("%lld%lld%lld",&l,&r,&x);
			add[l]+=x;
			add[r+1]-=x;
		}
		for(i=2;i<=n+1;i++)
		{
			add[i]+=add[i-1];
		}
		for(i=1;i<=n;i++)
		{
			if(i==n) printf("%lld\n",a[i]-add[i]);
			else printf("%lld ",a[i]-add[i]);
		}
	}
	return 0;
}