#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
struct ll_hash{size_t operator()(ll x)const{return x;}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,i,ans;
	while(~scanf("%d",&n))
	{
		ans=0;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=1;i<n-1;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1]) ans++;
			else if(a[i]<a[i-1]&&a[i]<a[i+1]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}