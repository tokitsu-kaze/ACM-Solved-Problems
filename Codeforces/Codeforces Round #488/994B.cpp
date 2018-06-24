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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
PLL a[MAX];
ll ans[MAX],v[MAX];
int main()
{
	int i,n,k;
	ll now;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=n;i++) scanf("%lld",&a[i].fi),a[i].se=i;
		for(i=1;i<=n;i++) scanf("%lld",&v[i]);
		sort(a+1,a+1+n);
		now=0;
		priority_queue<ll,vector<ll>,greater<ll> > q;
		for(i=1;i<=k+1;i++)
		{
			ans[a[i].se]=now+v[a[i].se];
			q.push(v[a[i].se]);
			now+=v[a[i].se];
		}
		for(i=k+2;i<=n;i++)
		{
			now-=q.top();
			q.pop();
			ans[a[i].se]=now+v[a[i].se];
			q.push(v[a[i].se]);
			now+=v[a[i].se];
		}
		for(i=1;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	}
	return 0;
}
