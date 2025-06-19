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
int a[MAX],b[MAX],w[MAX];
int main()
{
	int n,m,i,s,ans,ban;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d%d%d",&a[i],&b[i],&w[i]);
	ans=ban=0;
	for(s=30;~s;s--)
	{
		dsu.init(n);
		for(i=1;i<=m;i++)
		{
			if((w[i]&ban)>0) continue;
			if(!((w[i]>>s)&1)) dsu.merge(a[i],b[i]);
		}
		if(dsu.find(1)==dsu.find(n)) ban|=(1<<s);
		else ans|=(1<<s);
	}
	printf("%d\n",ans);
	return 0;
}
