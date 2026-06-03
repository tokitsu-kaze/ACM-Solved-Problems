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
vector<int> mp[MAX];
ll v[MAX],tag[MAX];
int main()
{
	int n,q,op,x,y,i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		mp[i].push_back(i);
		v[i]=tag[i]=0;
	}
	dsu.init(n);
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op<=3) scanf("%d",&y);
		if(op==1)
		{
			x=dsu.find(x);
			y=dsu.find(y);
			if(x==y) continue;
			if(mp[x].size()>mp[y].size()) swap(x,y);
			for(auto &it:mp[x])
			{
				mp[y].push_back(it);
				v[it]=v[it]+tag[x]-tag[y];
			}
			mp[x].clear();
			dsu.merge(x,y,true);
		}
		else if(op==2) v[x]+=y;
		else if(op==3) tag[dsu.find(x)]+=y;
		else printf("%lld\n",v[x]+tag[dsu.find(x)]);
	}
	return 0;
}
