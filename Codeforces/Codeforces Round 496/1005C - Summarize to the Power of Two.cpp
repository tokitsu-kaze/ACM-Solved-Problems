#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int a[MAX];
int main()
{
	int i,j,n,ans,flag;
	while(~scanf("%d",&n))
	{
		hash_map<int,int> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			mp[a[i]]--;
			flag=1;
			for(j=0;(1LL<<j)<2*mod;j++)
			{
				if(mp[(1LL<<j)-a[i]])
				{
					flag=0;
					break;
				}
			}
			ans+=flag;
			mp[a[i]]++;
		}
		printf("%d\n",ans);
	}
	return 0;
}