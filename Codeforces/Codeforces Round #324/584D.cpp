#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int prime[MAX];
vector<int> p;
void init(int n)
{
	int i,j;
	mem(prime,0);
	p.clear();
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		p.pb(i);
		for(j=i+i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
VI res;
int check(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
void gao(int n)
{
	if(n==3)
	{
		res.pb(3);
		return;
	}
	if(n==5)
	{
		res.pb(5);
		return;
	}
	n-=3;
	res.pb(3);
	for(auto it:p)
	{
		if(check(n-it))
		{
			res.pb(it);
			res.pb(n-it);
			return;
		}
	}
}
int main()
{
	int n;
	init(MAX-10);
	while(~scanf("%d",&n))
	{
		res.clear();
		gao(n);
		printf("%d\n",sz(res));
		for(int i=0;i<sz(res);i++) printf("%d%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}