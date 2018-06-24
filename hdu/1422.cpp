////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-10 09:17:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1422
////Problem Title: 
////Run result: Accept
////Run time:608MS
////Run memory:2452KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const int MAX=2e5+10;
const ll mod=1e9+7;
int d[MAX];
int main()
{
	int n,i,pre,ans,now,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			d[n+i]=d[i]=a-b;;
		}
		ans=now=0;
		pre=1;
		for(i=1;i<=2*n;i++)
		{
			now+=d[i];
			if(now<0)
			{
				pre=i+1;
				now=0;
			}
			else ans=max(ans,i-pre+1);
		}
		printf("%d\n",min(ans,n));
	}
	return 0;
}