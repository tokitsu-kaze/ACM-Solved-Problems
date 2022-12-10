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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=998244353;
int cnt[MAX],f[MAX],h[MAX],k;
ll dp[5050];
ll gao(int x)
{
	int i,j,l;
	if(!f[x]) return 0;
	for(i=0;i<=cnt[x];i++) dp[i]=0;
	while(f[x]--)
	{
		for(i=cnt[x];i;i--)
		{
			for(j=0;i-j>=0&&j<=k;j++)
			{
				dp[i]=max(dp[i],dp[i-j]+h[j]);
			}
		}
	}
//	cout<<x<<" "<<dp[cnt[x]]<<endl;
	return dp[cnt[x]];
}
int main()
{
	int n,i,x;
	ll ans;
	while(~scanf("%d%d",&n,&k))
	{
		mem(cnt,0);
		mem(f,0);
		for(i=1;i<=n*k;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			f[x]++;
		}
		h[0]=0;
		for(i=1;i<=k;i++) scanf("%d",&h[i]);
		ans=0;
		for(i=1;i<=MAX-10;i++) ans+=gao(i);
		printf("%lld\n",ans);
	}
	return 0;
}
