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
const int MAX=1e4+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int ni[2222];
int main()
{
	int i,j,n,a[2222],b[2222],pos[2222],p,ans;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) pos[b[i]]=i;
		for(i=1;i<=n;i++) a[i]=pos[a[i]];
	//	for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		vector<PII > res;
		ans=0;
		for(i=n;i;i--)
		{
			p=i;
			for(j=i+1;j<=a[p];j++)
			{
				if(a[j]<=p)
				{
					swap(a[p],a[j]);
					ans+=abs(p-j);
					res.pb(MP(p,j));
					p=j;
				}
			}
		}
		printf("%d\n",ans);
		printf("%d\n",sz(res));
		for(i=0;i<sz(res);i++) printf("%d %d\n",res[i].fi,res[i].se);
	}
	return 0;
}