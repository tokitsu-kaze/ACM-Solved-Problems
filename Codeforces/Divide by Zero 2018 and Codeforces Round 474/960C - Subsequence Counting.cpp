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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll x,d,i,tmp,now;
	while(~scanf("%lld%lld",&x,&d))
	{
		vector<ll> ans;
		for(tmp=1;(tmp<<1)<x;tmp<<=1);
		now=1;
		while(x)
		{
			while(tmp-1>x) tmp>>=1;
			if(tmp>1)
			{
				x-=tmp-1;
				for(i=1;i<tmp;i<<=1) ans.pb(now);
			}
			else
			{
				x--;
				ans.pb(now);
			}
			now+=d+1;
		}
		printf("%d\n",sz(ans));
		for(i=0;i<sz(ans);i++) printf("%lld%c",ans[i]," \n"[i==sz(ans)-1]);
	}
	return 0;
}