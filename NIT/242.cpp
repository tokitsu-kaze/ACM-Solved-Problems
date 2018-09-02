#include <bits/stdc++.h>
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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int n,i,x,ans,a[12];
	while(~scanf("%d",&n))
	{
		mem(a,0);
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x%10]++;
		}
		ans+=a[0];
		for(i=1;i<=4;i++) ans+=min(a[i],a[10-i]);
		ans+=a[5]/2;
		printf("%d\n",ans);
	}
	return 0;
}