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
int x[MAX];
int main()
{
	int n,i,cnt[2],minn,maxx;
	while(~scanf("%d",&n))
	{
		minn=INF;
		maxx=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
			minn=min(minn,x[i]);
			maxx=max(maxx,x[i]);
		}
		mem(cnt,0);
		for(i=0;i<n;i++)
		{
			if(x[i]==minn) cnt[0]++;
			if(x[i]==maxx) cnt[1]++;
		}
		ll ans;
		if(minn==maxx) ans=1LL*cnt[0]*(cnt[0]-1)/2;
		else ans=1LL*cnt[0]*cnt[1];
		printf("%d %lld\n",maxx-minn,ans);
	}
	return 0;
}