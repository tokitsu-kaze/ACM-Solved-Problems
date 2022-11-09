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
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,i,j;
	ll ans;
	vector<int> res;
	for(i=1;(1LL<<i)<=(int)2e9;i++)
	{
		res.pb(1<<i);
	}
	while(~scanf("%d",&n))
	{
		hash_map<int,int> mp;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		sort(a,a+n);
		n=unique(a,a+n)-a;
		ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<sz(res);j++)
			{
				if(res[j]<=a[i]) continue;
				int temp=res[j]-a[i];
				if(temp==a[i]) ans+=(ll)mp[a[i]]*(mp[a[i]]-1);
				else ans+=(ll)mp[a[i]]*mp[temp];
			}
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}