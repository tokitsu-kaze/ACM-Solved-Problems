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
const int MAX=2e5+10;
const ll mod=1e9+7;
ll a[MAX],bit[MAX];
int main()
{
	ll n,m,i,now,p,x,flag;
	while(~scanf("%lld%lld",&n,&m))
	{
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			bit[i]=bit[i-1]+a[i];
		}
		now=0;
		p=0;
		while(m--)
		{
			flag=0;
			scanf("%lld",&x);
			x+=bit[p]-now;
	//		cout<<p<<" "<<now<<endl;
			p=lower_bound(bit+1,bit+1+n,x)-bit;
			now=bit[p]-x;
			if(bit[p]>x)
			{
				p--;
				flag=1;
			}
			if(p>=n)  now=p=0;
			printf("%lld\n",n-p);
			p+=flag;
		}
	}
	return 0;
}