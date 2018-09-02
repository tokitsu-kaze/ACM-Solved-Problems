#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int main()
{
	int n,k,i,j,x,ans,l,now;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=MAX-10;i++) mp[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x].pb(i);
		}
		ans=1;
		for(i=1;i<=MAX-10;i++)
		{
			if(!sz(mp[i])) continue;
			l=0;
			now=0;
			for(j=1;j<sz(mp[i]);j++)
			{
				now+=mp[i][j]-mp[i][j-1]-1;
				while(now>k&&l<=j)
				{
					now-=mp[i][l+1]-mp[i][l]-1;
					l++;
				}
				ans=max(ans,j-l+1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}