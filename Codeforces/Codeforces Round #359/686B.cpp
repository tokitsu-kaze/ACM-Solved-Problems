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
const double eps=1e-8;
const int MAX=5e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,pos,a[111],b[111];
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(a+1,a+n+1);
		vector<PII > ans;
		for(i=1;i<=n;i++)
		{
			if(b[i]==a[i]) continue;
			for(j=i+1;j<=n;j++)
			{
				if(b[j]==a[i])
				{
					pos=j;
					break;
				}
			}
			for(j=pos;j>i;j--)
			{
				ans.pb(MP(j-1,j));
				swap(b[j-1],b[j]);
			}
		}
		for(i=2;i<=n;i++) assert(b[i]>=b[i-1]);
		for(i=0;i<sz(ans);i++)
		{
			printf("%d %d\n",ans[i].fi,ans[i].se);
		}
	}
	return 0;
}