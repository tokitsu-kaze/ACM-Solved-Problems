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
const int MAX=5e5+10;
const ll mod=1e9+7;
/********************************* std-head *********************************/
int cnt[MAX][4],flag[MAX][4],mp[MAX][4];
int n;
void dfs(int x,int y,int f)
{
	if(mp[x][y]) return;
	if(flag[x][y]) return;
	flag[x][y]=1;
	cnt[x][y]++;
	if(x+f>=1&&x+f<=n) dfs(x+f,y,f);
	if(y+f>=1&&y+f<=3) dfs(x,y+f,f);
}
int main()
{
    int T;
	int k,i,j,a,b,ans;
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
		    mem(mp[i],0);
		    mem(cnt[i],0);
		}
		while(k--)
		{
			scanf("%d%d",&a,&b);
			mp[a][b]^=1;
		}
		ans=0;
		for(i=1;i<=n;i++) mem(flag[i],0);
		dfs(1,1,1);
		for(i=1;i<=n;i++) mem(flag[i],0);
		dfs(n,3,-1);
		cnt[1][1]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				ans+=(cnt[i][j]==2);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
