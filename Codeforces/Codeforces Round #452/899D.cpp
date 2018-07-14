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
vector<ll> res;
void init()
{
	ll i;
	res.clear();
	for(i=5;i<=(ll)1e10;i*=10) res.pb(i);
}
int main()
{
	ll n,i,pos,tmp,now,ans;
	init();
	while(~scanf("%lld",&n))
	{
		if(n<=4)
		{
			printf("%lld\n",n*(n-1)/2);
			continue;
		}
		pos=upper_bound(all(res),n)-res.begin()-1;
		ans=0;
		for(i=0;i<=8;i++)
		{
			tmp=i*res[pos]*2+res[pos]*2-1;
//			cout<<tmp<<endl;
			if(n<(tmp+1)/2) break;
			else if(n>(tmp-1)) ans+=tmp/2;
			else ans+=(n-(tmp+1)/2+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}