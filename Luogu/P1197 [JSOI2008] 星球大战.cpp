#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
vector<int> mp[MAX];
int flag[MAX],ans[MAX],a[MAX];
int main()
{
	int n,m,i,x,y,k,now;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		flag[i]=0;
	}
	while(m--)
	{
		scanf("%d%d",&x,&y);
		x++;
		y++;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	dsu.init(n);
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		a[i]++;
		flag[a[i]]=1;
	}
	now=n-k;
	for(i=1;i<=n;i++)
	{
		if(flag[i]) continue;
		for(auto &to:mp[i])
		{
			if(!flag[to]) now-=dsu.merge(i,to);
		}
	}
	ans[k+1]=now;
	for(i=k;i;i--)
	{
		now++;
		flag[a[i]]=0;
		for(auto &to:mp[a[i]])
		{
			if(!flag[to]) now-=dsu.merge(a[i],to);
		}
		ans[i]=now;
	}
	for(i=1;i<=k+1;i++) printf("%d\n",ans[i]);
	return 0;
}
