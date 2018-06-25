////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-05 23:36:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5461
////Problem Title: 
////Run result: Accept
////Run time:530MS
////Run memory:3472KB
//////////////////System Comment End//////////////////
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
const double eps=1e-6;
const int MAX=5e6+10;
const ll mod=1e9+7;
int main()
{
	int t,n,i,cas=1;
	ll aa,bb,x,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld%lld",&n,&aa,&bb);
		vector<PLL > a,b;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			a.pb(MP(aa*x*x,i));
			b.pb(MP(bb*x,i));
		}
		sort(all(a));
		sort(all(b));
		printf("Case #%d: ",cas++);
		if(a[n-1].se==b[n-1].se) ans=max(a[n-1].fi+b[n-2].fi,a[n-2].fi+b[n-1].fi);
		else ans=a[n-1].fi+b[n-1].fi;
		printf("%lld\n",ans);
	}
	return 0;
}