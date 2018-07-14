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
const double eps=1e-8;
const int MAX=5e3+10;
const ll mod=1e9+7;
int dp[MAX][MAX][2],ans;
int main()
{
	int n,i,j;
	char s[MAX],t[11];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++) scanf("%s",t),s[i]=t[0];
		mem(dp,0);
		ans=0;
		dp[0][0][1]=1;
		for(i=0;i<n;i++)
		{
			for(j=n;j>=0;j--)
			{
				int temp=(dp[i][j][0]+dp[i][j][1])%mod;
				if(s[i]=='s') dp[i+1][j][1]=temp;
				else dp[i+1][j+1][0]=temp;
				if(j) dp[i][j-1][1]=(dp[i][j-1][1]+dp[i][j][1])%mod;
			}
		}
		for(i=0;i<=n;i++)
		{
			ans+=dp[n][i][1];
			ans%=mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}