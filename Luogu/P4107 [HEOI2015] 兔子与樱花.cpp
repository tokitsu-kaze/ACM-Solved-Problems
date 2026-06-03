#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
vector<int> mp[MAX];
int c[MAX],son[MAX],m,ans;
void dfs(int x)
{
	for(auto &to:mp[x]) dfs(to);
	sort(mp[x].begin(),mp[x].end(),[&](int a,int b){
		return son[a]+c[a]<son[b]+c[b];
	});
	for(auto &to:mp[x])
	{
		if(son[x]+c[x]+son[to]+c[to]-1<=m)
		{
			son[x]+=son[to]-1;
			c[x]+=c[to];
			ans++;
			son[to]=c[to]=0;
		}
	}
}
int main()
{
	int n,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%d",&son[i]);
		mp[i].resize(son[i]);
		for(auto &it:mp[i])
		{
			scanf("%d",&it);
			it++;
		}
	}
	ans=0;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
/*
自底向上：
对于x，按son+c对孩子从小到大排序，能删则删
*/
