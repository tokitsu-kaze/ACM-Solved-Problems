////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-05 15:29:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6273
////Problem Title: 
////Run result: Accept
////Run time:327MS
////Run memory:2464KB
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=998244353;
int cnt[2][MAX];
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
int main()
{
	int t,n,m,i,l,r,x,minn[2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(cnt,0);
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&x);
			x-=2;
			cnt[x][l]++;
			cnt[x][r+1]--;
		}
		mem(minn,0x3f);
		for(i=1;i<=n;i++)
		{
			cnt[0][i]+=cnt[0][i-1];
			cnt[1][i]+=cnt[1][i-1];
			minn[0]=min(minn[0],cnt[0][i]);
			minn[1]=min(minn[1],cnt[1][i]);
		}
		printf("%lld\n",pow2(2,minn[0])*pow2(3,minn[1])%mod);
	}
	return 0;
}
