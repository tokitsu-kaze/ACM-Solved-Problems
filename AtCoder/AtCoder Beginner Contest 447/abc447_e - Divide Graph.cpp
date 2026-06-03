#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
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
int pw2[MAX];
int a[MAX],b[MAX];
int main()
{
	int n,m,i,now,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
	pw2[0]=1;
	for(i=1;i<=m;i++) pw2[i]=pw2[i-1]*2LL%mod;
	dsu.init(n);
	now=n;
	ans=0;
	for(i=m;i;i--)
	{
		if(now==2)
		{
			if(dsu.find(a[i])!=dsu.find(b[i])) ans=(ans+pw2[i])%mod;
		}
		else
		{
			if(dsu.merge(a[i],b[i])) now--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
