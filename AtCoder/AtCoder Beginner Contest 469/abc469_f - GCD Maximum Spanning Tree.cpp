#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
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
vector<int> id[MAX];
int a[MAX];
int main()
{
	int n,i,j,rt;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<MAX;i++) id[i].clear();
	for(i=1;i<=n;i++) id[a[i]].push_back(i);
	dsu.init(n);
	ans=0;
	for(i=MAX-1;i;i--)
	{
		rt=-1;
		for(j=i;j<MAX;j+=i)
		{
			for(auto &x:id[j])
			{
				if(rt==-1) rt=x;
				else
				{
					if(dsu.merge(x,rt)) ans+=i;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
