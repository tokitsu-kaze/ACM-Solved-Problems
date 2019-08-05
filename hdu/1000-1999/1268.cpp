////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-07 10:21:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1268
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:4812KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a1[MAX],a2[MAX];//每一层来看的木块数目
ll b1[MAX],b2[MAX];//竖着看，存某一高度木块出现的次数
ll maxx1,maxx2,maxx;
ll w,l;
void input()
{
	mem(a1,0);
	mem(a2,0);
	mem(b1,0);
	mem(b2,0);
	ll n,i,j;
	for(i=0;i<w;i++)
	{
		scanf("%lld",&n);
		b1[n]++;
		maxx1=max(maxx1,n);
		for(j=1;j<=n;j++) a1[j]++;
	}
	for(i=0;i<l;i++)
	{
		scanf("%lld",&n);
		b2[n]++;
		maxx2=max(maxx2,n);
		for(j=1;j<=n;j++) a2[j]++;
	}
}
int main()
{
	ll i;
	while(~scanf("%lld%lld",&w,&l))
	{
		maxx=maxx1=maxx2=-1;
		input();
		if(maxx1!=maxx2)//若正视图也侧视图的高度不等则剪枝
		{
			printf("No solution.\n");
			continue;
		}
		maxx=max(maxx1,maxx2);
		ll ans=0,anw=0;//最少与最长
		for(i=0;i<=maxx;i++)
		{
			if(b1[i]||b2[i])
			{
				ans+=max(b1[i],b2[i])*i;//贪的关键
			}
			anw+=a1[i]*a2[i];
		}
		printf("%lld %lld\n",ans,anw);
	}
	return 0;
}