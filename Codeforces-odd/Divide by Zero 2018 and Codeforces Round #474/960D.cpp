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
ll work(ll x)
{
	ll res=0;
	while(x)
	{
		x>>=1;
		res++;
	}
	return res;
}
ll a[66],b[66],pow2[66];
int main()
{
	ll i,j,q,op,x,k,h;
	for(i=1,j=1;j<=61;i<<=1,j++) pow2[j]=i;
	while(~scanf("%lld",&q))
	{
		mem(a,0);
		mem(b,0);
		while(q--)
		{
			scanf("%lld%lld",&op,&x);
			h=work(x);
			if(op==1)
			{
				scanf("%lld",&k);
				k%=pow2[h];
				a[h]=(a[h]+k+pow2[h])%pow2[h];
			}
			else if(op==2)
			{
				scanf("%lld",&k);
				k%=pow2[h];
				b[h]=(b[h]+k+pow2[h])%pow2[h];
			}
			else if(op==3)
			{
				for(i=h;i;i--,x>>=1)
				{
					ll ans;
					if(i==h) ans=x;
					else ans=pow2[i]+(x-a[i]+pow2[i])%pow2[i];
					printf("%lld%c",ans," \n"[i==1]);
					if(i==h) x=pow2[i]+(x+a[i])%pow2[i];
					x=pow2[i]+(x+b[i])%pow2[i];
				}
			}
		}
	}
	return 0;
}