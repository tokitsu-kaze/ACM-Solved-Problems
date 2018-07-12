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
const int MAX=2e5+10;
const ll mod=1e9+7;
int main()
{
	ll n,a,b,i,x,vx,vy;
	ll ans;
	while(~scanf("%lld%lld%lld",&n,&a,&b))
	{
		map<ll,ll> cnt;
		map<ll,map<ll,ll> > mp;
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&x,&vx,&vy);
			cnt[a*vx-vy]++;
			mp[a*vx-vy][vx]++;
		}
		map<ll,map<ll,ll> > ::iterator it;
		map<ll,ll> ::iterator it2;
		ans=0;
		for(it=mp.begin();it!=mp.end();it++)
		{
			for(it2=(it->se).begin();it2!=(it->se).end();it2++)
			{
				ans+=it2->se*(cnt[it->fi]-it2->se);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}