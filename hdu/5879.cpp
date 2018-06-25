////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-07 12:22:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5879
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:10096KB
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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
char s[MAX];
double ans[MAX];
int main()
{
	ll i;
	int n;
	ans[0]=0;
	for(i=1;i<=MAX-10;i++)
	{
		ans[i]=ans[i-1]+1.0/(i*i);
	}
	while(~scanf("%s",s))
	{
		if(strlen(s)>=7) n=MAX-10;
		else n=atoi(s);
		printf("%.5lf\n",ans[n]);
	}
	return 0;
}