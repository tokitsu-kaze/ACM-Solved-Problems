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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int flag[MAX];
int main()
{
	int n,i,j,a[1011],g;
	while(~scanf("%d",&n))
	{
		mem(flag,0);
		g=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			flag[a[i]]=1;
			g=__gcd(g,a[i]);
		}
		if(g!=a[0])
		{
			puts("-1");
			continue;
		}
		printf("%d\n",2*n);
		printf("%d %d",a[0],a[0]);
		for(i=1;i<n;i++)
		{
			printf(" %d %d",a[0],a[i]);
		}
		puts("");
	}
	return 0;
}