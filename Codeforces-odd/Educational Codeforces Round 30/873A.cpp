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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int n,x,k,a[211],i,ans;
	while(~scanf("%d%d%d",&n,&x,&k))
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=n;i<n+x;i++)
		{
			a[i]=k;
		}
		sort(a,a+n+x);
		for(i=0;i<n;i++)
		{
			ans+=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}