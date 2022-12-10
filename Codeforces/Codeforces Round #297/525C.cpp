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
const int MAX=1e6+10;
const ll mod=1e9+7;
int cnt[MAX];
int main()
{
	int n,i,x;
	ll ans;
	while(~scanf("%d",&n))
	{
		mem(cnt,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		vector<int> res;
		for(i=MAX-10;i;i--)
		{
			while(cnt[i+1]&&cnt[i])
			{
				res.pb(i);
				cnt[i+1]--;
				cnt[i]--;
			}
			while(cnt[i]>=2)
			{
				res.pb(i);
				cnt[i]-=2;
			}
		}
		sort(all(res));
		ans=0;
		for(i=sz(res)-1;i>=1;i-=2)
		{
			ans+=1LL*res[i]*res[i-1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4
2 3 3 4
*/