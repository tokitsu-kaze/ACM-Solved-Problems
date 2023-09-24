#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll l,r,x,y,k,i,j;
	while(~scanf("%lld%lld%lld%lld%lld",&l,&r,&x,&y,&k))
	{
		int flag=0;
		for(i=x;i<=y;i++)
		{
			ll temp=i*k;
			if(temp>=l&&temp<=r)
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
8 8 2 5 3
*/