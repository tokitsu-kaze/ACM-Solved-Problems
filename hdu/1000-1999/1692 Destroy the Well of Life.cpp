////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-06 21:00:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1692
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:2848KB
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
int a[MAX],b[MAX],c[MAX];
int main()
{
	int t,i,j,n,ans,now,w,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
		ans=INF;
		for(i=1;i<=n;i++)
		{
			now=w=0;
			for(j=i;j<=n;j++)
			{
				w+=a[j];
				if(w<=b[j]) now+=c[j];
				if(now>ans) break;
			}
			ans=min(ans,now);
		}
		printf("Case %d: Need to use %d mana points.\n",cas++,ans);
	}
	return 0;
}