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
int res[MAX][12];
int main()
{
	int T,n,m,a,d,k,i,j,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		dsu.init(n);
		for(i=1;i<=n;i++) memset(res[i],0,sizeof res[i]);
		while(m--)
		{
			scanf("%d%d%d",&a,&d,&k);
			res[a][d]=max(res[a][d],k);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=10;j++)
			{
				if(res[i][j]>0)
				{
					dsu.merge(i,i+j);
					res[i+j][j]=max(res[i+j][j],res[i][j]-1);
				}
			}
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(dsu.find(i)==i) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}

