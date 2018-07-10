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
int n,m,a[MAX];
int main()
{
	int i,j,pos,mx,mn;
	ll ans;
	while(~scanf("%d%d",&n,&m))//比m大-比m小 [0,1] 
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==m) pos=i;
		}
		ans=0;
		hash_map<int,int> mp;
		mn=mx=0;
		for(i=pos-1;i;i--)
		{
			if(a[i]>m) mx++;
			else mn++;
			mp[mx-mn]++;
		}
		ans+=mp[0]+mp[1];
		mn=mx=0;
		for(i=pos+1;i<=n;i++)
		{
			if(a[i]>m) mx++;
			else mn++;
			if(mx-mn==0||mx-mn==1) ans++;
			ans+=mp[0-(mx-mn)]+mp[1-(mx-mn)];
		}
		printf("%lld\n",ans+1);
	}
	return 0;
}