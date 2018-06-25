////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-12 19:12:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5916
////Problem Title: 
////Run result: Accept
////Run time:171MS
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int t,i,cas=1,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		printf("Case #%d:",cas++);
		if(n==2)
		{
			puts(" 2 1");
			continue;
		}
		if(k==1)
		{
			for(i=1;i<=n;i++) printf(" %d",i);
			puts("");
			continue;
		}
		printf(" %d",2*k);
		for(i=k;i>=1;i--) printf(" %d",i);
		for(i=k+1;i<=n;i++)
		{
			if(i==2*k) continue;
			else printf(" %d",i);
		}
		puts("");
	}
	return 0;
}