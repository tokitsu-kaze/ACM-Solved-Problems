////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-29 18:40:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4704
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2640KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x)
{
	return pow2(x,mod-2);
}
int main()
{
	ll ans,i,len,temp;
	char a[MAX];
	while(~scanf("%s",a))
	{
		len=strlen(a);
		temp=2;
		ans=1;
		for(i=len-1;i>=0;i--)
		{
			ans=ans*pow2(temp,a[i]-'0')%mod;
			temp=pow2(temp,10)%mod;
		}
		printf("%lld\n",ans*inv(2)%mod);
	}
	return 0;
}