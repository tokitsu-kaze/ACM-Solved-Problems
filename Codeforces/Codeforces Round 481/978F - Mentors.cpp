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
const int MAX=2e5+10;
const ll mod=1e9+7;
int ans[MAX],tmp[MAX];
PII v[MAX];
int main()
{
	int n,m,i,a,b,now;
	while(~scanf("%d%d",&n,&m))
	{
		mem(ans,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i].fi);
			tmp[i]=v[i].fi;
			v[i].se=i;
		}
		sort(v+1,v+1+n);
		now=1;
		ans[v[1].se]=now-1;
		for(i=2;i<=n;i++)
		{
			if(v[i].fi==v[i-1].fi);
			else now=i;
			ans[v[i].se]=now-1;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			if(tmp[a]<tmp[b]) ans[b]--;
			else if(tmp[a]>tmp[b]) ans[a]--;
		}
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}