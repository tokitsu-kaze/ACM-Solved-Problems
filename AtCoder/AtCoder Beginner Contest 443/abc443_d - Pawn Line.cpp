#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int dir[2]={-1,1};
int a[MAX],vis[MAX][2];
int main()
{
	int T,n,i,mn,t,nex,tmp;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		mn=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mn=min(mn,a[i]);
			vis[i][0]=vis[i][1]=0;
		}
		ans=0;
		priority_queue<pair<int,int>> q;
		for(i=1;i<=n;i++) q.push({-a[i],i});
		while(!q.empty())
		{
			auto it=q.top();
			q.pop();
			for(i=0;i<2;i++)
			{
				t=it.second;
				nex=t+dir[i];
				if(nex<1||nex>n) continue;
				tmp=max(0,a[nex]-a[t]-1);
				ans+=tmp;
				a[nex]-=tmp;
				if(tmp>0) assert(!vis[nex][i]);
				if(!vis[nex][i])
				{
					vis[nex][i]=1;
					q.push({-a[nex],nex});
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
只能减。考虑从最小的开始 bfs。
每个点最多被更新2次。
初始队列应该把所有数都塞进去，
例子：
1 x x x 2
更新为
1 2 x x 2
此时只有位置2的那个2在队列里，
这样就违背了每次将全局最小的弹出队列进行更新。 
*/
