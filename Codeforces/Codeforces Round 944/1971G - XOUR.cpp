#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int a[MAX],ans[MAX];
vector<int> res[MAX];
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		map<int,int> pos;
		dsu.init(n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(pos.count(a[i])) dsu.merge(pos[a[i]],i);
			pos[a[i]]=i;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<4;j++)
			{
				if(!pos.count(a[i]^j)) continue;
				dsu.merge(pos[a[i]^j],i);
			}
		}
		for(i=1;i<=n;i++) res[i].clear();
		for(i=1;i<=n;i++) res[dsu.find(i)].push_back(i);
		for(i=1;i<=n;i++)
		{
			if(res[i].size()==0) continue;
			vector<int> tmp(res[i]);
			sort(res[i].begin(),res[i].end(),[](int x,int y){
				return a[x]<a[y];
			});
			for(j=0;j<tmp.size();j++) ans[tmp[j]]=a[res[i][j]];
		}
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}
