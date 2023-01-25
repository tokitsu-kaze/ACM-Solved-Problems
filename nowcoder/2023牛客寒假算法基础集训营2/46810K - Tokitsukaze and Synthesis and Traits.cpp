#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/********************************* std-head *********************************/
VI mp[MAX];
int flag[MAX],d[MAX];
int main()
{
	int n,m,q,k,i,j,a,b,ans;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++) mp[i].clear();
	mem(flag,0);
	VPII e;
	while(m--)
	{
		scanf("%d%d",&a,&b);
		e.pb(MP(a,b));
		d[a]++;
		d[b]++;
	}
	for(auto it:e)
	{
		if(d[it.fi]<d[it.se]) mp[it.fi].pb(it.se);
		else mp[it.se].pb(it.fi);
	}
	while(q--)
	{
		scanf("%d",&k);
		VI x(k);
		for(auto &it:x)
		{
			scanf("%d",&it);
			flag[it]=1;
		}
		ans=0;
		for(auto it:x)
		{
			for(auto to:mp[it]) ans+=flag[to];
		}
		for(auto it:x) flag[it]=0;
		printf("%d\n",ans);
	}
	return 0;
}

