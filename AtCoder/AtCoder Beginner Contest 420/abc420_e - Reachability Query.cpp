#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX],cnt[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
			cnt[i]=0;
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
		cnt[y]+=cnt[x];
		return 1;
	}
}dsu;
int col[MAX];
int main()
{
	int n,q,i,op,x,y;
	scanf("%d%d",&n,&q);
	dsu.init(n);
	for(i=1;i<=n;i++) col[i]=0;
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			dsu.merge(x,y);
		}
		else if(op==2)
		{
			if(col[x]==0) dsu.cnt[dsu.find(x)]++;
			else dsu.cnt[dsu.find(x)]--;
			col[x]^=1;
		}
		else
		{
			if(dsu.cnt[dsu.find(x)]>0) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
