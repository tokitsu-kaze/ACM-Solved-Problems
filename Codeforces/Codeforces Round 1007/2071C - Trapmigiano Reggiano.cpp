#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=1e5+10;
vector<int> mp[MAX],res;
void dfs(int x,int fa)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
	res.push_back(x);
}
int main()
{
	int T,n,i,a,b,s,e;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&s,&e);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		res.clear();
		dfs(e,0);
		for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i+1==n]);
	}
	return 0;
}

