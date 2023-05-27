#include <bits/stdc++.h>
using namespace std;
vector<int> mp[105];
int cnt[105],dep[105],mxdep,wide,fa[105],flag[105];
void dfs(int x,int pre,int h)
{
	cnt[h]++;
	dep[x]=h;
	fa[x]=pre;
	wide=max(wide,cnt[h]);
	mxdep=max(mxdep,h);
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x,h+1);
	}
}
int main()
{
	int n,i,a,b,x,y,tmp,lca;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);		
	}
	scanf("%d%d",&x,&y);
	memset(cnt,0,sizeof cnt);
	mxdep=0;
	wide=0;
	dfs(1,0,1);
	printf("%d\n",mxdep);
	printf("%d\n",wide);
	memset(flag,0,sizeof flag);
	tmp=x;
	while(tmp)
	{
		flag[tmp]=1;
		tmp=fa[tmp];
	}
	tmp=y;
	while(tmp)
	{
		if(flag[tmp])
		{
			lca=tmp;
			break;
		}
		tmp=fa[tmp];
	}
	printf("%d\n",(dep[x]-dep[lca])*2+dep[y]-dep[lca]);
	return 0;
}
