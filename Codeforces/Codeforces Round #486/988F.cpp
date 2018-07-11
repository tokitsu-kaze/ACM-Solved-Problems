#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int dp[2020];
int flag[2020],w[2020];
int main()
{
	int d,n,m,i,j,l,r;
	while(~scanf("%d%d%d",&d,&n,&m))
	{
		mem(flag,0);
		while(n--)
		{
			scanf("%d%d",&l,&r);
			flag[l]++;
			flag[r]--;
		}
		for(i=0;i<=d;i++) flag[i]+=flag[i-1];
		mem(w,0);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&l,&r);
			if(!w[l]) w[l]=r;
			else w[l]=min(w[l],r);
		}
		mem(dp,0x3f);
		dp[0]=0;
		for(i=1;i<=d;i++)
		{
			if(flag[i-1])
			{
				for(j=0;j<=i-1;j++)
				{
					if(!w[j]) continue;
					dp[i]=min(dp[i],dp[j]+w[j]*(i-j));
				}
			}
			else dp[i]=min(dp[i],dp[i-1]);
	//		cout<<dp[i]<<endl;
		}
		if(dp[d]==INF) puts("-1");
		else printf("%d\n",dp[d]);
	}
	return 0;
}
