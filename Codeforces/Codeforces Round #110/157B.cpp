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
	int n,i,r[111],flag;
	double ans;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&r[i]);
		}
		sort(r+1,r+n+1);
		ans=0;
		flag=1;
		for(i=n;i>=1;i--)
		{
			if(flag) ans+=r[i]*r[i]*PI;
			else ans-=r[i]*r[i]*PI;
			flag++;
			flag%=2;
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}