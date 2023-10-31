#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
vector<int> mp[MAX];
int ans[MAX];
void dfs(int x,int now)
{
	if(ans[x]) return;
	ans[x]=now;
	for(auto &to:mp[x]) dfs(to,now);
}
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		ans[i]=0;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[b].push_back(a);
	}
	for(i=n;i;i--) dfs(i,i);
	for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
