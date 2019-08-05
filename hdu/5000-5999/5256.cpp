////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-14 00:15:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5256
////Problem Title: 
////Run result: Accept
////Run time:452MS
////Run memory:2436KB
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
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX],b[MAX],n;
int LIS()
{
	int i;
	mem(b,0x3f);
	for(i=0;i<n;i++)
	{
		*upper_bound(b,b+n,a[i])=a[i];
	}
	return lower_bound(b,b+n,INF)-b;
}
int main()
{
	int i,t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			a[i]-=i+1;
		}
		printf("Case #%d:\n",cas++);
		printf("%d\n",n-LIS());
	}
	return 0;
}