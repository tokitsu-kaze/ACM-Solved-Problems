#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
vector<int> mp[MAX],res;
int a[MAX],fa[MAX],vis[MAX];
void dfs(int x)
{
	if(res.size()) return;
	int t;
	vis[x]=1;
	for(auto &to:mp[x])
	{
		if(res.size()) return;
		fa[to]=x;
		if(vis[to])
		{
			t=x;
			res.push_back(t);
			while(t!=to)
			{
				t=fa[t];
				res.push_back(t);
			}
		}
		else dfs(to);
	}
}
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mp[i].clear();
			mp[i].push_back(i-a[i]);
			vis[i]=0;
		}
		res.clear();
		dfs(1);
		printf("%d\n",(int)res.size());
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}
/*
把条件变形一下，变成 1<=i-ai<=n。
看着就很连边，连 i -> (i-ai)，有环就有解。
n 个点 n 条边显然是基环树，所以一定有解。
*/
