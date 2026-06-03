#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int op[MAX],x[MAX],y[MAX],in[MAX],tpn[MAX];
void topsort(int n)
{
	int tot,i;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	tot=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		tpn[x]=++tot;
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
}
int main()
{
	int T,n,m,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			in[i]=tpn[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&op[i],&x[i],&y[i]);
			if(op[i]==1)
			{
				mp[x[i]].push_back(y[i]);
				in[y[i]]++;
			}
		}
		topsort(n);
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(tpn[i]==0) ok=0;
		}
		if(!ok)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=1;i<=m;i++)
		{
			if(op[i]==0)
			{
				if(tpn[x[i]]>tpn[y[i]]) swap(x[i],y[i]);
			}
			printf("%d %d\n",x[i],y[i]);
		}
	}
	return 0;
}
/*
给无向边定向，要求最后的图是dag。
先只保留有向边跑拓扑排序，然后按拓扑序连。
*/
