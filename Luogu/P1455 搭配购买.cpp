#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e4+10;
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
	bool merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(sz[x]>sz[y]) swap(x,y);
		pre[x]=y;
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
int dp[MAX],c[MAX],d[MAX],w[MAX],v[MAX];
int main()
{
	int n,m,k,i,j,a,b,rt;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
		w[i]=v[i]=0;
	}
	dsu.init(n);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		dsu.merge(a,b);
	}
	for(i=1;i<=n;i++)
	{
		rt=dsu.find(i);
		w[rt]+=c[i];
		v[rt]+=d[i];
	}
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		if(v[i]==0) continue;
		for(j=k;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	printf("%d\n",*max_element(dp,dp+1+k));
	return 0;
}
