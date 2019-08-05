////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-14 12:37:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5933
////Problem Title: 
////Run result: Accept
////Run time:436MS
////Run memory:2464KB
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[MAX];
int main()
{
	ll t,cas=1,i,j,n,k,ans,s,now;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			s+=a[i];
		}
		printf("Case #%lld: ",cas++);
		if(s%k)
		{
			puts("-1");
			continue;
		}
		s/=k;
		now=ans=0;
		for(i=1;i<=n;i++)
		{
			if(now) ans++;
			now+=a[i];
			while(now>s)
			{
				now-=s;
				ans++;
			}
			if(now==s) now=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}