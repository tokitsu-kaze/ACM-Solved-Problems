////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-12 18:32:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5912
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[22],b[22],n;
PII dfs(int now)
{
	if(now==n) return MP(b[n]+a[n-1]*a[n],a[n]);
	PII res=dfs(now+1);
	if(now==1) return MP(b[now]*res.se,res.fi);
	else return MP(b[now]*res.se+a[now-1]*res.fi,res.fi);
}
int main()
{
	int t,i,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
		}
		PII ans=dfs(1);
		int g=__gcd(ans.fi,ans.se);
		printf("Case #%d: %d %d\n",cas++,ans.fi/g,ans.se/g);
	}
	return 0;
}