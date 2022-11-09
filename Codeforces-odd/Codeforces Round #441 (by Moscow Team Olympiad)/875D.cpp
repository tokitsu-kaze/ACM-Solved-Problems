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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-3;
const int MAX=2e5+10;
const ll mod=1e9+7;
int a[MAX],pos[33],l[MAX],r[MAX];
int main()
{
	int n,i,j;
	ll ans;
	while(~scanf("%d",&n))
	{
		mem(pos,0);
		mem(l,0);
		mem(r,0);
		map<int,int> last;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++)
		{
			l[i]=last[a[i]];
			for(j=0;j<32;j++)
			{
				if((a[i]&(1LL<<j))==0) l[i]=max(l[i],pos[j]);
				else pos[j]=i;
			}
			last[a[i]]=i;
		}
		for(i=0;i<32;i++) pos[i]=n+1;
		for(i=n;i>=1;i--)
		{
			r[i]=n+1;
			for(j=0;j<32;j++)
			{
				if((a[i]&(1LL<<j))==0) r[i]=min(r[i],pos[j]);
				else pos[j]=i;
			}
		}
		ans=(ll)n*(n+1)/2;
		for(i=1;i<=n;i++)
		{
			ans-=(ll)(i-l[i])*(r[i]-i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}