#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAX=2e5+10;
struct node{int x,w;};
vector<node> mp[MAX];
int flag[MAX],val[MAX],ok;
void dfs(int x,int now)
{
	flag[x]=2;
	val[x]=now;
	for(auto &to:mp[x])
	{
		if(flag[to.x]==1) continue;
		if(flag[to.x]==2)
		{
			if(to.w^now^val[to.x]) ok=0;
			continue;
		}
		dfs(to.x,now^to.w);
	}
	flag[x]=1;
}
int main()
{
	int t,n,m,i,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			flag[i]=val[i]=0;
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[a].pb({b,c});
			mp[b].pb({a,c});
		}
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(flag[i]) continue;
			dfs(i,0);
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
