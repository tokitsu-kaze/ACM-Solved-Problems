////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-01-29 17:10:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4472
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
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
const double eps=1e-8;
const int MAX=5e5+10;
const ll mod=1e9+7;
int main()
{
	int n,cas=1,i,j,dp[1111];
	mem(dp,0);
	dp[1]=1;
	dp[2]=1;
	dp[3]=2;
	dp[4]=3;
	for(i=5;i<=1000;i++)
	{
		for(j=1;j<i;j++)
		{
			if((i-1)%j==0)
			{
				dp[i]+=dp[j];
				dp[i]%=mod;
			}
		}
	}
	while(~scanf("%d",&n))
	{
		printf("Case %d: %d\n",cas++,dp[n]);
	}
	return 0;
}