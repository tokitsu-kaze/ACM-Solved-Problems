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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll n,i,j,mp[111][15],cnt[111],k,val[111][15],now;
	ll ans;
	while(~scanf("%lld",&n))
	{
		ans=-LLINF;
		for(i=0;i<n;i++)
		{
			for(j=0;j<10;j++) scanf("%lld",&mp[i][j]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<=10;j++) scanf("%lld",&val[i][j]);
		}
		for(i=1;i<(1<<10);i++)
		{
			mem(cnt,0);
			for(j=0;j<10;j++)
			{
				if(i&(1<<j))
				{
					for(k=0;k<n;k++)
					{
						cnt[k]+=mp[k][j];
					}
				}
			}
			now=0;
			for(k=0;k<n;k++) now+=val[k][cnt[k]];
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
