#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[MAX],b[MAX],bit[MAX],cnt[MAX],v[MAX];
int main()
{
	int i,n,pos;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
			bit[i]=b[i]+bit[i-1];
		}
		bit[n+1]=INF;
		mem(cnt,0);
		mem(v,0);
		for(i=1;i<=n;i++)
		{
			pos=lower_bound(bit+i,bit+1+n,a[i]+bit[i-1])-bit;
			v[pos]+=a[i]-(bit[pos-1]-bit[i-1]);
			cnt[i]++;
			cnt[pos]--;
			cnt[i]+=cnt[i-1];
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",v[i]+cnt[i]*b[i]," \n"[i==n]);
		}
	}
	return 0;
}