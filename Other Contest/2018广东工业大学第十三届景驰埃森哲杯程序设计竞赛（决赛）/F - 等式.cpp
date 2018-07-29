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
vector<int> p;
bool flag[MAX];
void init()
{
	int i,j;
	p.clear();
	mem(flag,0);
	for(i=2;i<=MAX-10;i++)
	{
		if(!flag[i])
		{
			p.pb(i);
			for(j=i+i;j<=MAX-10;j+=i)
			{
				flag[j]=1;
			}
		}
	}
}
int main()
{
	init();
	ll n,i,ans,cnt;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		vector<ll> res;
		for(i=0;i<sz(p);i++)
		{
			if(n==1) break;
			if(n%p[i]==0)
			{
				cnt=0;
				while(n%p[i]==0)
				{
					n/=p[i];
					cnt++;
				}
				res.pb(cnt*2+1);
			}
		}
		if(n!=1) res.pb(3);
		ans=1;
		for(i=0;i<sz(res);i++)
		{
			ans*=res[i];
		}
		printf("%lld\n",ans/2+1);
	}
	return 0;
}