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
const int MAX=5e5+10;
const ll mod=1e9+7;
int main()
{
	int a[11],b[11],n,m,i,ans;
	while(~scanf("%d%d",&n,&m))
	{
		map<int,int> mp;
		ans=INF;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
			if(mp[b[i]]) ans=min(ans,b[i]);
		}
		sort(a,a+n);
		sort(b,b+m);
		if(ans==INF) ans=min(a[0]*10+b[0],b[0]*10+a[0]);
		printf("%d\n",ans);
	}
	return 0;
}