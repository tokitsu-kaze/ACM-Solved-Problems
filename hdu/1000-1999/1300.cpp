////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-06 17:50:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1300
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
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
const int MAX=1e4+10;
const ll mod=1e9+7;
int main()
{
	int t,n,i,j,dp[111],cnt,a[111],b[111],bit[111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		dp[0]=bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			bit[i]=bit[i-1]+a[i];
			dp[i]=(bit[i]+10)*b[i];
			for(j=1;j<i;j++) dp[i]=min(dp[i],dp[j]+(bit[i]-bit[j]+10)*b[i]);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}