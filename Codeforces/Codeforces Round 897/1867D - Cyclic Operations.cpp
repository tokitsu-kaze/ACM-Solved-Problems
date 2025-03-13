#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int to[MAX],in[MAX],vis[MAX],ok,dep[MAX],k;
void dfs(int x,int len)
{
	if(vis[x]==2) return;
	vis[x]=1;
	dep[x]=len;
	if(vis[to[x]]==1)
	{
		if(len-dep[to[x]]+1!=k) ok=0;
		vis[x]=2;
		return;
	}
	dfs(to[x],len+1);
	vis[x]=2;
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) in[i]=vis[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&to[i]);
			in[to[i]]++;
		}
		if(k==1)
		{
			ok=1;
			for(i=1;i<=n;i++)
			{
				if(to[i]!=i) ok=0;
			}
			if(ok) puts("YES");
			else puts("NO");
			continue;
		}
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(in[i]) continue;
			dfs(i,0);
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			dfs(i,0);
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
