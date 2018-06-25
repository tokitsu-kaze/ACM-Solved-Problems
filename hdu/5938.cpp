////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-14 13:15:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5938
////Problem Title: 
////Run result: Accept
////Run time:156MS
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll len;
char s[22];
ll cal(ll p1,ll p2,ll p3)
{
	ll a1,b1,a2,b2,c,d,e,i;
	if(p1<2) return -LLINF;
	e=0;
	for(i=p3;i<len;i++)
	{
		e=e*10+s[i]-'0';
	}
	d=s[p2]-'0';
	c=s[p1]-'0';
	a1=0;
	for(i=0;i<p1-1;i++)
	{
		a1=a1*10+s[i]-'0';
	}
	b1=s[p1-1]-'0';
	a2=s[0]-'0';
	b2=0;
	for(i=1;i<p1;i++)
	{
		b2=b2*10+s[i]-'0';
	}
	return max(a1+b1,a2+b2)-c*d/e;
}
int main()
{
	ll t,cas=1,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",s);
		len=strlen(s);
		ans=-LLINF;
		ans=max(ans,cal(len-3,len-2,len-1));
		ans=max(ans,cal(len-4,len-3,len-2));
		ans=max(ans,cal(len-5,len-4,len-3));
		printf("Case #%lld: %lld\n",cas++,ans);
	}
	return 0;
}
/*
100
111991
11991
*/