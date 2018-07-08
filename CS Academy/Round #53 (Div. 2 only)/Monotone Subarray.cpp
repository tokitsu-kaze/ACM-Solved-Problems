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
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,i,l,r,ans;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		ans=0;
		l=r=0;
		for(i=1;i<n;i++)
		{
			if(a[i-1]<=a[i]) r=i;
			else
			{
				ans=max(ans,r-l+1);
				l=r=i;
			}
		}
		ans=max(ans,r-l+1);
		l=r=0;
		for(i=1;i<n;i++)
		{
			if(a[i-1]>=a[i]) r=i;
			else
			{
				ans=max(ans,r-l+1);
				l=r=i;
			}
		}
		ans=max(ans,r-l+1);
		printf("%d\n",ans);
	}
	return 0;
}
