#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=8e3+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,a[111][111],ans,l[111],r[111];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		mem(l,0);
		mem(r,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				l[i]+=a[i][j];
				r[j]+=a[i][j];
			}
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(r[j]>l[i]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}