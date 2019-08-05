////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-11 01:08:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6253
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:1680KB
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
const int MAX=2e6+10;
const ll mod=1e9+7;
int main()
{
	ull t,n,cas=1,ans[]={1,9,41,109};
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu",&n);
		printf("Case #%llu: ",cas++);
		if(n<=3) printf("%llu\n",ans[n]);
		else printf("%llu\n",7*n*n+4*n+1+7*(n-1)*(n-1)+4*(n-1)+1);
		
	}
	return 0;
} 
