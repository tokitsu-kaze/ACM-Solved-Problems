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
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
ll a[MAX],bit[MAX],r[MAX];
int main()
{
	ll n,k,i,j,nex,now,ans,pre;
	while(~scanf("%lld%lld",&n,&k))
	{
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			bit[i]=bit[i-1]+a[i];
			r[i]=i+1;
		}
		bit[n+1]=bit[n];
		nex=n+1;
		for(i=n;i>=1;i--)
		{
			while(i>=1&&a[i]==1) r[i--]=nex;
			r[i]=nex;
			nex=i;
		}
		r[n]=n+1;
		ans=0;
		for(i=1;i<=n;i++)
		{
	//		cout<<r[i]<<endl;
			now=1;
			pre=i;
			for(j=i;j<=n+1;j=r[j])
			{
				if(pre!=j&&now%k==0&&(bit[pre]-bit[i-1])*k<now&&(bit[j-1]-bit[i-1])*k>=now) ans++;
				if(j==n+1) break;
				if(now>=4e18/a[j]) break;
				now*=a[j];
				if(now==(bit[j]-bit[i-1])*k) ans++;
				pre=j;
				if(j==n) break;
	//			cout<<i<<" "<<j<<" "<<ans<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
6 1
1 2 5 1 1 1
*/
