#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
ll res[2];
void dfs(int x,int pre,int now)
{
	int i,flag=0;
	res[now%2]++;
	for(i=0;i<sz(mp[x]);i++)
	{
		if(mp[x][i]!=pre)
		{
			flag=1;
			dfs(mp[x][i],x,now+1);
		}
	}
}
int main()
{
	int n,i,a,b,s;
	while(~scanf("%d",&n))
	{
		mem(res,0);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		dfs(1,0,1);
		printf("%lld\n",res[0]*res[1]-(n-1));
	}
	return 0;
}