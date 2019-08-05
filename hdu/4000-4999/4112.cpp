////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-18 18:22:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4112
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll t,cas=1,a,b,c,ans1,ans2,d,e,f;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		ans1=a*b*c-1;
		d=e=f=ans2=0;
		while(a>1)
		{
			if(a%2) d=1;
			a>>=1;
			ans2++;
		}
		while(b>1)
		{
			if(b%2) e=1;
			b>>=1;
			ans2++;
		}
		while(c>1)
		{
			if(c%2) f=1;
			c>>=1;
			ans2++;
		}
		printf("Case #%lld: %lld %lld\n",cas++,ans1,ans2+d+e+f);
	}
	return 0;
}