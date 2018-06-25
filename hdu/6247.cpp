////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-11 01:03:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6247
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1672KB
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
	int t,n,x,i,ans,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			ans+=x+(x+9)/10;
		}
		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
} 
