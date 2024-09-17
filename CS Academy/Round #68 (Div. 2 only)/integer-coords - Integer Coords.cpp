#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int ans,k,x1,x2,y1,y2,n,m;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		ans=0;
		for(x1=0;x1<=n;x1++)
		{
			for(y1=0;y1<=m;y1++)
			{
				for(x2=0;x2<=n;x2++)
				{
					for(y2=0;y2<=m;y2++)
					{
						if(__gcd(abs(x1-x2),abs(y1-y2))+1==k) ans++;
					}
				}
			}
		}
		printf("%d\n",ans/2);
	}
	return 0;
}