////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-14 15:52:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5935
////Problem Title: 
////Run result: Accept
////Run time:514MS
////Run memory:2448KB
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
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[MAX];
int main()
{
	ll t,cas=1,i,n,ans,x,l,r,temp,g;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		a[1]=0;
		for(i=2;i<=n+1;i++)
		{
			scanf("%lld",&a[i]);
		}
		l=a[n+1]-a[n];
		r=1;
		ans=1;
		for(i=n-1;i>=1;i--)
		{
			x=a[i+1]-a[i];
			temp=x*r/l+(((x*r)%l)?1:0);
//			cout<<x<<" "<<temp<<" "<<l<<" "<<r<<endl;
			ans+=temp;
			l=x;
			r=temp;
		}
		printf("Case #%lld: %lld\n",cas++,ans);
	}
	return 0;
}