#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],vis[MAX],n,m,tmp[5];
map<pair<int,int>,int> mp;
void dfs(int x,int h)
{
	int i,cnt;
	tmp[h]=x;
	for(i=1;i<=m;i++)
	{
		if(a[i]==x || b[i]==x) vis[i]++;
	}
	if(h==2)
	{
		cnt=0;
		for(i=1;i<=m;i++) cnt+=(vis[i]>0);
		if(cnt==m)
		{
			if(tmp[1]>tmp[2]) mp[{tmp[2],tmp[1]}]=1;
			else mp[{tmp[1],tmp[2]}]=1;
		}
		for(i=1;i<=m;i++)
		{
			if(a[i]==x || b[i]==x) vis[i]--;
		}
		return;
	}
	for(i=1;i<=m;i++)
	{
		if(!vis[i])
		{
			dfs(a[i],h+1);
			dfs(b[i],h+1);
			break;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(a[i]==x || b[i]==x) vis[i]--;
	}
}
int tag[MAX];
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) tag[i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		tag[a[i]]++;
		tag[b[i]]++;
	}
	mp.clear();
	for(i=1;i<=n;i++)
	{
		if(tag[i]!=m) continue;
		for(j=1;j<=n;j++)
		{
			if(j==i) continue;
			if(i<j) mp[{i,j}]=1;
			else mp[{j,i}]=1;
		}
	}
	
	for(i=1;i<=m;i++) vis[i]=0;
	dfs(a[1],1);
	dfs(b[1],1);
	printf("%d\n",(int)mp.size());
	return 0;
}
/*
4 3
1 2
1 2
1 2
*/
