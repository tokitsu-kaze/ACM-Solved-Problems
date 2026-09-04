#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int to,id;};
vector<node> mp[MAX];
int a[MAX],b[MAX],vis[MAX];
char ans[MAX];
void dfs(int x)
{
	vis[x]=1;
	for(auto &it:mp[x])
	{
		if(ans[it.id]!='.') continue;
		if(x==a[it.id] && it.to==b[it.id]) ans[it.id]='0';
		else ans[it.id]='1';
		if(!vis[it.to]) dfs(it.to);
	}
}
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		vis[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		mp[a[i]].push_back({b[i],i});
		mp[b[i]].push_back({a[i],i});
		ans[i]='.';
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i]) dfs(i);
	}
	ans[m+1]='\0';
	puts(ans+1);
	return 0;
}
/*
把给定的图看作拆点，把操作看成给边定向。
按照dfs生成树的顺序定向即可。
*/
