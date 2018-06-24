////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-13 23:23:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5053
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1748KB
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
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=10000+10;
const ll mod=1e9+7;
ll bit[MAX];
int main()
{
	int t,cas=1;
	ll i,a,b;
	mem(bit,0);
	for(i=1;i<=10000;i++)
	{
		bit[i]=bit[i-1]+i*i*i;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		printf("Case #%d: %lld\n",cas++,bit[b]-bit[a-1]);
	} 
	return 0;
}