#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-10;
const int MAX=5e4+10;
const ll mod=1e9+7;
int main()
{
	ll n,x,i,ans;
	while(~scanf("%lld",&n))
	{
		ans=0;
		priority_queue<ll,vector<ll>,greater<ll> > q;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			if(!q.empty()&&q.top()<x)
			{
				ans+=x-q.top();
				q.pop();
				q.push(x);
			}
			q.push(x);
		}
		printf("%lld\n",ans);
	} 
	return 0;
}