#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll k,i,j,now;
	while(~scanf("%lld",&k))
	{
		now=100000;
		for(i=0;i<26;i++)
		{
			while(now*(now-1)/2>k) now--;
			for(j=0;j<now;j++)
			{
				putchar('a'+i);
			}
			k-=now*(now-1)/2;
		}
		puts("");
	}
	return 0;
}