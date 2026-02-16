#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int ban[MAX],sz[MAX],fa[MAX];
ll ans[MAX];
void dfs(int x,int pre)
{
	sz[x]=1;
	fa[x]=pre;
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
		sz[x]+=sz[to];
	}
}
int main()
{
	int T,n,i,a,b,sum,x,y,p,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{
			mp[i].clear();
			ban[i]=0;
			ans[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		dfs(0,0);
		ans[1]=0;
		sum=1;
		for(auto &to:mp[0])
		{
			ans[1]+=1LL*sz[to]*sum;
			sum+=sz[to];
		}
		ans[0]=1LL*n*(n-1)/2-ans[1];
		ban[0]=1;
		x=y=0;
		p=1;
		for(i=1;i<n;i++)
		{
			if(ban[i]==0)
			{
				now=i;
				while(ban[now]==0)
				{
					ban[now]=1;
					if(i==1) p=now;
					now=fa[now];
					if(x==now)
					{
						x=i;
						break;
					}
					if(y==now)
					{
						y=i;
						break;
					}
				}
				if(x!=i&&y!=i) break;
			}
			ban[i]=1;
			if(x>y) swap(x,y);
			if(x==0) ans[i+1]=1LL*(sz[0]-sz[p])*sz[y];
			else ans[i+1]=1LL*sz[x]*sz[y];
		}
		for(i=1;i<n;i++) ans[i]-=ans[i+1];
		for(i=0;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	}
	return 0;
}
