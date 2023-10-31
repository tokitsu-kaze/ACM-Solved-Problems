#include bitsstdc++.h
using namespace std;
#pragma comment(linker, STACK1024000000,1024000000)
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include exthash_map
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pairint,int PII;
typedef pairll,ll PLL;
typedef vectorint VI;
typedef vectorll VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
  head  
int main()
{
	int n,m,i,j;
	while(~scanf(%d%d,&n,&m))
	{
		if(n-1m)
		{
			puts(Impossible);
			continue;
		}
		vectorPII  res;
		for(i=1;i=n;i++)
		{
			for(j=i+1;j=n;j++)
			{
				if(__gcd(i,j)!=1) continue;
				res.pb(MP(i,j));
				if(sz(res)==m) goto end;
			}
		}
		end;
		if(sz(res)m)
		{
			puts(Impossible);
			continue;
		}
		else
		{
			puts(Possible);
			for(auto itres)
			{
				printf(%d %dn,it.fi,it.se);
			}
		}
	}
	return 0;
}