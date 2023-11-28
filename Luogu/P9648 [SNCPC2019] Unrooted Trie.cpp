#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct node{int x,c;};
vector<node> mp[MAX];
int ans,sum[MAX],v[MAX],cnt[MAX][26];
void dfs0(int x,int fa)
{
	int i,to;
	for(auto &it:mp[x])
	{
		to=it.x;
		if(to==fa) continue;
		cnt[x][it.c]++;
	}
	for(i=0;i<26;i++)
	{
		if(cnt[x][i]>1) v[x]++;
	}
	sum[x]=v[x];
	for(auto &it:mp[x])
	{
		to=it.x;
		if(to==fa) continue;
		dfs0(to,x);
		sum[x]+=sum[to];
	}
}
void dfs(int x,int fa)
{
	int i,to;
	if(sum[x]==0) ans++;
	for(auto &it:mp[x])
	{
		to=it.x;
		if(to==fa) continue;
		sum[x]-=v[x];
		cnt[x][it.c]--;
		if(cnt[x][it.c]==1) v[x]--;
		sum[x]+=v[x];
		sum[x]-=sum[to];
		sum[to]+=sum[x];
		
		sum[to]-=v[to];
		cnt[to][it.c]++;
		if(cnt[to][it.c]==2) v[to]++;
		sum[to]+=v[to];
		
		dfs(to,x);
		
		sum[to]-=v[to];
		cnt[to][it.c]--;
		if(cnt[to][it.c]==1) v[to]--;
		sum[to]+=v[to];
		
		sum[to]-=sum[x];
		sum[x]+=sum[to];
		
		sum[x]-=v[x];
		cnt[x][it.c]++;
		if(cnt[x][it.c]==2) v[x]++;
		sum[x]+=v[x];
	}
}
int main()
{
	int t,n,i,a,b;
	char c[2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			v[i]=sum[i]=0;
			memset(cnt[i],0,sizeof cnt[i]);
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d%s",&a,&b,c);
			mp[a].push_back({b,c[0]-'a'});
			mp[b].push_back({a,c[0]-'a'});
		}
		dfs0(1,0);
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}

