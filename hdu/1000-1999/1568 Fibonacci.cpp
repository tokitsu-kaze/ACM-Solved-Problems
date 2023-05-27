////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-01-27 19:59:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1568
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
const double eps=1e-8;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int f[222];
	int i,n;
	double ans;
	f[0]=0;
	f[1]=1;
	for(i=2;i<=20;i++) f[i]=f[i-1]+f[i-2];
	while(~scanf("%d",&n))
	{
		if(n<=20)
		{
			printf("%d\n",f[n]);
			continue;
		}
		ans=log10(1.0/sqrt(5))+n*log10((1+sqrt(5))/2);
		ans=ans-(int)ans;
		ans=pow(10,ans);
		while(ans<1000) ans*=10;
		printf("%d\n",(int)ans);
	}
	return 0;
}