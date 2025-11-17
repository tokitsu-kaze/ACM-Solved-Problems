#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
void dfs(int x,int fa,int f)
{
	if(f==0) printf("%d %d\n",fa,x);
	else printf("%d %d\n",x,fa);
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,f^1);
	}
}
int main()
{
	int T,n,i,a,b,rt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		rt=0;
		for(i=1;i<=n;i++)
		{
			if(mp[i].size()==2) rt=i;
		}
		if(rt==0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		dfs(mp[rt][0],rt,0);
		dfs(mp[rt][1],rt,1);
	}
	return 0;
}
