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
const int MAX=2e5+10;
const ll mod=1e9+7;
int l[MAX],r[MAX],a[MAX],b[MAX];
int main()
{
	int n,m,i,ans;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&l[i],&a[i]);
		}
		sort(a,a+n);
		scanf("%d",&m);
		ans=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&b[i],&r[i]);
			ans=max(ans,max(0,b[i]-a[0]));
		}
		sort(r,r+m);
		for(i=0;i<n;i++)
		{
			ans=max(ans,max(0,l[i]-r[0]));
		}
		printf("%d\n",ans);
	}
	return 0;
}