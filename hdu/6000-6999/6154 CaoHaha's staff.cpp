////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-19 21:36:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6154
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
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
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	ll t,n,i,temp,ans,x;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n<8)
		{
			if(n==1) puts("4");
			else if(n==2) puts("4");
			else if(n==3) puts("6");
			else if(n==4) puts("6");
			else if(n==5) puts("7");
			else if(n==6||n==7) puts("8");
			continue;
		}
		temp=(ll)sqrt(n/2);
		ans=temp*4;
		x=temp*temp*2;
		if(n==x);
		else if(n<=x+temp-0.5) ans++;
		else if(n<=x+2*temp) ans+=2;
		else if(n<=x+3*temp+0.5) ans+=3;
		else ans+=4;
		printf("%lld\n",ans);
	}
	return 0;
}