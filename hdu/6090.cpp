////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-08 17:19:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll n,m,ans,temp,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		if(n==1)
		{
			puts("0");
			continue;
		}
		if(n==2)
		{
			puts("2");
			continue;
		}
		if(m>=n*(n-1)/2)
		{
			printf("%lld\n",n*(n-1));
			continue;
		}
		ans=n*(n-1)*n-(n-1)*2;
		temp=(n-3)*2+3;
		if(n>=3&&m>=2) ans-=temp*2;
		if(n>=4&&m>=3)
		{
			if(m<=n-1) ans-=((m-1)*(temp-1)+temp*4)*(m-2)/2;
			else ans-=((n-2)*(temp-1)+temp*4)*(n-3)/2;
		}
		if(n>=3&&m>n-1) ans-=(m-n+1)*2;
		printf("%lld\n",ans);
	}
	return 0;
}
