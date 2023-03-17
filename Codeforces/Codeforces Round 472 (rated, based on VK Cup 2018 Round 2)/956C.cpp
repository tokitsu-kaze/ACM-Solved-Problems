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
int a[MAX],b[MAX];
int main()
{
	int n,i;
	ll ans;
	while(~scanf("%d",&n))
	{
		b[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=b[i-1];
			b[i]=max(b[i],a[i]);
		}
		ans=0;
		b[n+1]=0;
		for(i=n;i;i--)
		{
			if(b[i]<b[i+1]-1) b[i]=b[i+1]-1;
			ans+=b[i]-a[i];
		}
//		for(i=1;i<=n;i++) printf("%d%c",b[i]," \n"[i==n]);
		printf("%lld\n",ans);
	}
	return 0;
}