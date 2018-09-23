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
string s[MAX][2];
int v[MAX];
ll dp[MAX][2];
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		for(i=1;i<=n;i++)
		{
			cin>>s[i][0];
			s[i][1]=s[i][0];
			reverse(all(s[i][1]));
		}
		mem(dp,0x3f);
		dp[1][0]=0;
		dp[1][1]=v[1];
		for(i=2;i<=n;i++)
		{
			if(s[i-1][0]<=s[i][0]) dp[i][0]=min(dp[i][0],dp[i-1][0]);
			if(s[i-1][0]<=s[i][1]) dp[i][1]=min(dp[i][1],dp[i-1][0]+v[i]);
			if(s[i-1][1]<=s[i][0]) dp[i][0]=min(dp[i][0],dp[i-1][1]);
			if(s[i-1][1]<=s[i][1]) dp[i][1]=min(dp[i][1],dp[i-1][1]+v[i]);
		}
		ll ans=min(dp[n][0],dp[n][1]);
		if(ans==LLINF) puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}