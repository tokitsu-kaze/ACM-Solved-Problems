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
ll a[MAX];
int main()
{
	ll n,k,l,i,j,ans,now,cnt;
	while(~scanf("%lld%lld%lld",&n,&k,&l))
	{
		for(i=0;i<n*k;i++) scanf("%lld",&a[i]);
		sort(a,a+n*k);
		if(a[n-1]-a[0]>l)
		{
			puts("0");
			continue;
		}
		ans=0;
		set<ll> s;
		for(i=0;i<n*k;i+=k) s.insert(i);
		while(1)
		{
			auto it=s.end();
			it--;
			if(a[*it]-a[0]<=l) break;
			ll tmp=*it;
			tmp--;
			s.erase(*it);
			cnt=1;
			while(cnt)
			{
				if(a[tmp]-a[0]>l)
				{
					if(s.count(tmp))
					{
						cnt++;
						s.erase(tmp);
					}
				}
				else
				{
					if(s.count(tmp));
					else
					{
						s.insert(tmp);
						cnt--;
					}
				}
				tmp--;
			}
		}
		for(auto it:s) ans+=a[it];
		printf("%lld\n",ans);
	}
	return 0;
}