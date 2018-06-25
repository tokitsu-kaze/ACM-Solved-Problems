////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-09 00:03:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6069
////Problem Title: 
////Run result: Accept
////Run time:2480MS
////Run memory:22092KB
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
const ll mod=998244353;
int flag[MAX];
vector<int> p;
void init()
{
	int i,j;
	p.clear();
	mem(flag,0);
	for(i=2;i<=MAX-10;i++)
	{
		if(flag[i]) continue;
		p.pb(i);
		for(j=i+i;j<=MAX-10;j+=i)
		{
			flag[j]=1;
		}
	}
}
ll x[MAX],cnt[MAX];
int main()
{
	ll t,l,r,k,i,j,limt,ans;
	init();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&l,&r,&k);
		for(i=l;i<=r;i++)
		{
			x[i-l]=i;
			cnt[i-l]=1;
		}
		limt=(ll)sqrt(r);
		for(i=0;i<sz(p)&&p[i]<=limt;i++)
		{
			j=l/p[i]*p[i];
			while(j<l) j+=p[i];
			for(;j<=r;j+=p[i])
			{
				ll temp=0;
				while(x[j-l]%p[i]==0)
				{
					temp++;
					x[j-l]/=p[i];
				}
				cnt[j-l]=cnt[j-l]*(k*temp+1)%mod;
			}
		}
		ans=0;
		for(i=l;i<=r;i++)
		{
			if(x[i-l]!=1) cnt[i-l]=cnt[i-l]*(k+1)%mod; 
			ans+=cnt[i-l];
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}