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
const int MAX=200000+10;
const ll mod=1e9+7;
int main()
{
	int n,k,i,x,ans,now;
	while(~scanf("%d%d",&n,&k))
	{
		map<int,int> mp;
		map<int,int> ::iterator it;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			mp[x]++;
		}
		vector<PII > res;
		for(it=mp.begin();it!=mp.end();it++)
		{
			res.pb(MP(it->se,it->fi));
		}
		if(sz(res)<=k)
		{
			puts("0");
			continue;
		}
		sort(all(res));
		ans=0;
		now=sz(res);
		for(i=0;i<sz(res);i++)
		{
			ans+=res[i].fi;
			now--;
			if(now<=k) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
