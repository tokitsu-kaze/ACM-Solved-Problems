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
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int i,n,a[111];
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(a[1]%2&&a[n]%2&&n%2) puts("Yes");
		else puts("No");
	}
	return 0;
}