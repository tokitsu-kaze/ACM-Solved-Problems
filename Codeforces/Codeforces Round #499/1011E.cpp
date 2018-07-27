#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int main()
{
	int n,k,g,x,i;
	while(~scanf("%d%d",&n,&k))
	{
		g=k;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			g=__gcd(g,x);
		}
		printf("%d\n",k/g);
		for(i=0;i<k;i+=g) printf("%d%c",i," \n"[i+g>=k]);
	}
	return 0;
}