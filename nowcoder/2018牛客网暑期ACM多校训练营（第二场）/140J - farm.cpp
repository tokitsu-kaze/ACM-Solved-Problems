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
const int MAX=1e6+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
VI v[MAX],cnt[MAX];
VL now[MAX];
int mp[MAX];
int main()
{
	int n,m,q,i,j,x1,x2,y1,y2,vv;
	while(~scanf("%d%d%d",&n,&m,&q))
	{
		for(i=1;i<=n*m;i++) mp[i]=i;
		random_shuffle(mp+1,mp+1+n*m);
		for(i=0;i<=n+1;i++)
		{
			v[i].resize(m+5);
			cnt[i].resize(m+5);
			now[i].resize(m+5);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&v[i][j]);
				v[i][j]=mp[v[i][j]];
				now[i][j]=0;
				cnt[i][j]=0;
			}
		}
		while(q--)
		{
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&vv);
			now[x1][y1]+=mp[vv];
			now[x1][y2+1]-=mp[vv];
			now[x2+1][y1]-=mp[vv];
			now[x2+1][y2+1]+=mp[vv];
			cnt[x1][y1]++;
			cnt[x1][y2+1]--;
			cnt[x2+1][y1]--;
			cnt[x2+1][y2+1]++;
		}
		int ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				now[i][j]+=now[i-1][j]+now[i][j-1]-now[i-1][j-1];
				cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
				if(now[i][j]!=1LL*cnt[i][j]*v[i][j]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}