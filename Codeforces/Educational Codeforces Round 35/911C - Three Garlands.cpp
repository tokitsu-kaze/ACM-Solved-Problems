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
int main()
{
	int a[5];
	while(~scanf("%d%d%d",&a[0],&a[1],&a[2]))
	{
		sort(a,a+3);
		if(a[0]==1) puts("YES");
		else if(a[0]==2&&a[1]==2) puts("YES");
		else if(a[0]==3&&a[1]==3&&a[2]==3) puts("YES");
		else if(a[0]==2&&a[1]==4&&a[2]==4) puts("YES");
		else puts("NO");
	}
	return 0;
}