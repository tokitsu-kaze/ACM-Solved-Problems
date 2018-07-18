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
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
int main()
{
	ll n,k,i,x,now,cnt;
	while(~scanf("%lld%lld",&n,&k))
	{
		queue<ll> q;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			q.push(x);
		}
		now=q.front();
		q.pop();
		cnt=0;
		while(cnt<min(k,n))
		{
			ll temp=q.front();
			q.pop();
			if(temp<now)
			{
				q.push(temp);
				cnt++;
			}
			else
			{
				cnt=1;
				q.push(now);
				now=temp;
			}
		}
		printf("%lld\n",now);
	}
	return 0;
}