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
const int MAX=2e5+10;
const int mod=1e9+7;
ll a[MAX];
int main()
{
	int n,i,t;
	ll j,tmp;
	while(~scanf("%d",&n))
	{
		hash_map<int,int> mp;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			mp[a[i]]++;
		}
		sort(a,a+n);
		vector<int> ans,now;
		for(i=0;i<n;i++)
		{
			for(j=0;j<=50;++j)
			{
				ll tmp=(1LL<<j)+a[i];
				now.clear();
				t=mp[a[i]];
				while(t--) now.pb(a[i]);
				if(tmp<=a[n-1])
				{
					auto it=mp.find(tmp);
					if(it!=mp.end())
					{
						t=it->second;
						while(t--) now.pb(it->first);
					}
				}
				tmp+=(1LL<<j);
				if(tmp<=a[n-1])
				{
					auto it=mp.find(tmp);
					if(it!=mp.end())
					{
						t=it->second;
						while(t--) now.pb(it->first);
					}
				}
				if(sz(ans)<sz(now)) swap(ans,now);
			}
		}
		printf("%d\n",sz(ans));
		for(i=0;i<sz(ans);i++) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
	}
	return 0;
}