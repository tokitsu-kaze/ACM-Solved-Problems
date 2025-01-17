#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
vector<int> mp[MAX];
int ans,d;
void dfs(int x,int fa,int h)
{
	if(h>0 && h<=d) ans++;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,h+1);
	}
}
int main()
{
	int n,i,a,b;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	ans=0;
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
