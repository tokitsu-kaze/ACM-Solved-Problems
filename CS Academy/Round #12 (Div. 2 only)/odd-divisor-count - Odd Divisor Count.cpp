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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int res[1111];
void init()
{
	int i,j;
	mem(res,0);
	for(i=1;i<=1000;i++)
	{
		for(j=1;j<=i;j++)
		{
			res[i]+=(i%j==0);
		}
		res[i]%=2;
		res[i]+=res[i-1];
	}
}
int main()
{
	init();
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		printf("%d\n",res[b]-res[a-1]);
	}
	return 0;
}