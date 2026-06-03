#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
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
int p[MAX],vis[MAX],mex[MAX],now[MAX],pos[MAX];
int main()
{
	int T,n,i,j,x,y,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		set<int> s;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			pos[p[i]]=i;
			now[i]=vis[i]=0;
			mex[i]=1;
		}
		dsu.init(n);
		for(i=1;i<=n;i++)
		{
			x=i;
			while(!vis[x])
			{
				vis[x]=1;
				dsu.merge(x,p[x]);
				x=p[x];
			}
		}
		for(i=1;i<=n;i++)
		{
			x=dsu.find(i);
			while(mex[x]<=n)
			{
				if(dsu.find(mex[x])!=x) break;
				mex[x]++;
			}
			if(mex[x]==n+1) continue;
//			printf("%d %d %d\n",i,x,mex[x]);
			now[x]++;
			if(mex[x]<p[i] || now[x]==dsu.sz[x])
			{
				y=dsu.find(mex[x]);
				mx=max(mex[x],mex[y]);
				dsu.merge(x,y);
				swap(p[i],p[pos[mex[x]]]);
				swap(pos[p[i]],pos[mex[x]]);
				mex[x]=mex[y]=mx;
				now[dsu.find(x)]=now[x]+now[y];
			}
//			for(j=1;j<=n;j++) printf("%d%c",p[j]," \n"[j==n]);
		}
		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	}
	return 0;
}
/*
最终目标是连成一个环，显然一次交换会合并两个环。
考虑字典序贪心，从前往后每次看不在当前环内的点的最小值，比较大小然后交换过来。
如果一个环内所有数都遍历过，那么选最后一个跟别的环交换一下。
问题转化成求当前环的mex，暴力即可。
每个环内暴力mex复杂度O(size)的，合并后取max，复杂度应该是启发式合并。
*/
