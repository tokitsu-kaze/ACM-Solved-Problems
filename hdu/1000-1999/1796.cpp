////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-10 16:38:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1796
////Problem Title: 
////Run result: Accept
////Run time:936MS
////Run memory:1680KB
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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int x,i,j,cnt,n,f[]={-1,1};
	ll ans,now,a[12];
	while(~scanf("%d%d",&x,&n))
	{
		x--;
		ans=0;
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		for(i=1;i<(1<<n);i++)
		{
			cnt=0;
			now=1;
			for(j=0;j<n;j++)
			{
				if((1<<j)&i)
				{
					now=now*a[j]/__gcd(now,a[j]);
					cnt++;
				}
			}
			if(now==0) continue;
			ans+=x/now*f[cnt&1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}