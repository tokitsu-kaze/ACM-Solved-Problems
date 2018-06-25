////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-11 19:06:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6237
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:2852KB
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
int flag[MAX];
void init()
{
	int i,j;
	mem(flag,0);
	for(i=2;i<=MAX;i++)
	{
		if(!flag[i])
		{
			for(j=i+i;j<=MAX;j+=i)
			{
				flag[j]=1;
			}
		}
	}
}
int bit[MAX],cnt[MAX];
int main()
{
	init();
	ll t,n,i,j,x,ans,s,maxx;
	ll sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		mem(bit,0);
		sum=0;
		maxx=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			bit[x]++;
			sum+=x;
			maxx=max(maxx,x);
		}
		ans=sum-maxx;
		for(i=2;i<=(ll)1e5;i++)
		{
			if(flag[i]) continue;
			if(sum%i) continue;
			mem(cnt,0);
			for(j=1;j<=(ll)1e5;j++)
			{
				cnt[j%i]+=bit[j];
			}
			ll res=0;
			for(j=1;j<i;j++)
			{
				res+=cnt[j]*j;
			}
			ll temp=res/i;
			for(j=i-1;j>=1;j--)
			{
				if(temp>=cnt[j])
				{
					res-=cnt[j]*j;
					temp-=cnt[j];
				}
				else
				{
					res-=j*temp;
					break;
				}
			}
			ans=min(ans,res);
	//		cout<<i<<" "<<res+s/i<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
100
4
1 2 4 42
*/
