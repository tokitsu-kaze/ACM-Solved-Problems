#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
#define PDD pair<double,double>
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=5e5+10;
const ll mod=998244353;
int main()
{
	int n,a[222],b;
	while(~scanf("%d%d",&n,&b))
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int pre[222],nex[222];
		pre[0]=0;
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(a[i]%2==0?-1:1);
		nex[n+1]=0;
		for(int i=n;i;i--) nex[i]=nex[i+1]+(a[i]%2==0?-1:1);
		VI res;
		for(int i=1;i<=n-1;i++)
		{
			if(pre[i]==0&&nex[i+1]==0) res.pb(abs(a[i+1]-a[i]));
		}
		int ans=0;
		sort(all(res));
		for(int i=0;i<sz(res);i++)
		{
			if(res[i]<=b)
			{
				ans++;
				b-=res[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}