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
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
int bit1[MAX],bit2[MAX],a[MAX];
int main()
{
	int n,k,i,ans;
	while(~scanf("%d%d",&n,&k))
	{
		if(k==1) ans=mod;
		else ans=-mod;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(k==1) ans=min(ans,a[i]);
			else ans=max(ans,a[i]);
		}
		if(k==1) printf("%d\n",ans);
		else if(k>=3) printf("%d\n",ans);
		else
		{
			if(ans==a[1]||ans==a[n])
			{
				printf("%d\n",ans);
				continue;
			}
			for(i=0;i<=n+1;i++)
			{
				bit1[i]=mod;
				bit2[i]=mod;
			}
			for(i=n;i>=1;i--)
			{
				bit2[i]=min(bit2[i+1],a[i]);
			}
			for(i=1;i<=n;i++)
			{
				bit1[i]=min(bit1[i-1],a[i]);
			}
			ans=-mod;
			for(i=2;i<=n;i++)
			{
				ans=max(ans,max(bit1[i-1],bit2[i]));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}