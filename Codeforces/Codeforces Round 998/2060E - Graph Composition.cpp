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
}dsuf,dsug;
int af[MAX],bf[MAX],ag[MAX],bg[MAX];
int main()
{
	int T,n,m1,m2,i,cntf,cntg,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m1,&m2);
		for(i=1;i<=m1;i++) scanf("%d%d",&af[i],&bf[i]);
		for(i=1;i<=m2;i++) scanf("%d%d",&ag[i],&bg[i]);
		dsug.init(n);
		for(i=1;i<=m2;i++) dsug.merge(ag[i],bg[i]);
		cntg=0;
		for(i=1;i<=n;i++) cntg+=(dsug.find(i)==i);
		dsuf.init(n);
		ans=0;
		for(i=1;i<=m1;i++)
		{
			if(dsug.find(af[i])==dsug.find(bf[i])) dsuf.merge(af[i],bf[i]);
			else ans++;
		}
		cntf=0;
		for(i=1;i<=n;i++) cntf+=(dsuf.find(i)==i);
		printf("%d\n",ans+cntf-cntg);
	}
	return 0;
}
