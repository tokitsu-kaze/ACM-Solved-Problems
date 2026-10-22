#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int s[MAX];
ll mx[MAX],ans;
void dfs(int x,int cnt)
{
	int i,ret;
	mx[x]=s[x];
	ans+=1LL*s[x]*cnt;
	if(mp[x].size()==0) return;
	ret=cnt%mp[x].size();
	for(auto &to:mp[x]) dfs(to,cnt/mp[x].size());
	sort(mp[x].begin(),mp[x].end(),[&](int a,int b){
		return mx[a]>mx[b];
	});
	for(i=0;i<ret;i++) ans+=mx[mp[x][i]];
	mx[x]=mx[mp[x][ret]]+s[x];
}
int main()
{
	int T,n,k,i,fa;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&fa);
			mp[fa].push_back(i);
		}
		for(i=1;i<=n;i++) scanf("%d",&s[i]);
		ans=0;
		dfs(1,k);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
就是每个节点的儿子平均分。
多出来的优先分配给往下走收益多的。
这个收益并不是最长链，而是多走一条路径的差。

1
6 3
1 1 2 3 3
0 0 0 19 20 18
ans=58
*/
