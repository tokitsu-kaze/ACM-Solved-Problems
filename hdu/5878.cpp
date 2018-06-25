////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-07 12:05:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5878
////Problem Title: 
////Run result: Accept
////Run time:592MS
////Run memory:2108KB
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
const int MAX=1e3+10;
const ll mod=1e9+7;
vector<ll> res;
map<ll,int> mp;
void init()
{
	ll i,a[]={2,3,5,7},t;
	queue<ll> q;
	res.clear();
	mp.clear();
	q.push((ll)1);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		res.pb(t);
		for(i=0;i<4;i++)
		{
			if(t*a[i]>(ll)1e9) continue;
			if(mp.count(t*a[i])) continue;
			q.push(t*a[i]);
			mp[t*a[i]]=1;
		}
	}
	sort(all(res));
}
int main()
{
	int t;
	ll n;
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",*lower_bound(all(res),n));
	}
	return 0;
}