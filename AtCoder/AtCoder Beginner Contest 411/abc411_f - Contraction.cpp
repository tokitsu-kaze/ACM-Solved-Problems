#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
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
set<int> s[MAX];
int a[MAX],b[MAX];
int main()
{
	int n,m,i,q,x,y,z,p,ans,rt;
	scanf("%d%d",&n,&m);
	dsu.init(n);
	for(i=1;i<=n;i++) s[i].clear();
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		s[a[i]].insert(b[i]);
		s[b[i]].insert(a[i]);
	}
	ans=m;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&p);
		x=dsu.find(a[p]);
		y=dsu.find(b[p]);
		if(x!=y)
		{
			if(s[x].size()>s[y].size()) swap(x,y);
			dsu.merge(x,y,true);
			assert(s[y].count(x));
			s[x].erase(y);
			s[y].erase(x);
			ans--;
			for(auto &it:s[x])
			{
				s[it].erase(x);
				if(s[y].count(it)) ans--;
				else
				{
					s[y].insert(it);
					s[it].insert(y);
				}
			}
			s[x].clear();
		}
		printf("%d\n",ans);
	}
	return 0;
}
