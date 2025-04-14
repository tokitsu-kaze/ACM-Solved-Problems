#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
struct Disjoint_Set_Union_Roll_Back
{
	pair<int,int> st[MAX];
	int pre[MAX],top,sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
		top=0;
	}
	int find(int x)
	{
		while(x!=pre[x]) x=pre[x];
		return x;
	}
	bool merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(sz[x]>sz[y]) swap(x,y);
		pre[x]=y;
		sz[y]+=sz[x];
		st[top++]={x,y};
		return 1;
	}
	void roll_back()
	{
		pair<int,int> now=st[--top];
		pre[now.first]=now.first;
		sz[now.second]-=sz[now.first];
	}
}dsu_rb;
vector<int> mp[MAX];
int cnt[MAX],ans[MAX],res[MAX];
int main()
{
	int n,m,i,a,b,now,mn;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		cnt[i]=res[i]=0;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dsu_rb.init(n);
	for(i=2;i<=n;i++)
	{
		cnt[i]=0;
		for(auto &to:mp[i])
		{
			if(to>i) continue;
			cnt[i]+=dsu_rb.merge(i,to);
		}
	}
	if(dsu_rb.sz[dsu_rb.find(1)]!=n) ans[n]=-1;
	else ans[n]=0;
	now=0;
	dsu.init(n);
	for(i=n;i>=2;i--)
	{
		while(cnt[i]--) dsu_rb.roll_back();
		for(auto &to:mp[i])
		{
			if(to<i)
			{
				now++;
				break;
			}
		}
		mn=n;
		for(auto &to:mp[i]) mn=min(mn,to);
		if(mn<i) res[mn]++;
		now-=res[i];
		if(dsu_rb.sz[dsu_rb.find(1)]!=i-1) ans[i-1]=-1;
		else ans[i-1]=now;
	}
	for(i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
