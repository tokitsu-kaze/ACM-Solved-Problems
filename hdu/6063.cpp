////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-01 19:22:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6063
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1524KB
//////////////////System Comment End//////////////////
#include<stdio.h>
typedef long long ll;const ll m=1e9+7;ll p(ll a,ll b){ll r=1;while(b){if(b&1) r=r*a%m;a=a*a%m;b>>=1;}return r;}main(){ll n,k,c=1;while(~scanf("%lld%lld",&n,&k)){n%=m;printf("Case #%lld: %lld\n",c++,p(n,k));}}