#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
vector<int> mp[MAX];
int m,v[MAX],ans;
void dfs(int x,int fa,int now,int mx)
{
	if(v[x]==1) now++;
	else now=0;
	mx=max(mx,now);
	if(x!=1 && mp[x].size()==1 && mx<=m) ans++;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,now,mx);
	}
}
int main()
{
	int n,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%d",&v[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	ans=0;
	dfs(1,0,0,0);
	printf("%d\n",ans);
	return 0;
}
