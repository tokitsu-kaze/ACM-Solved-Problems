#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int d[MAX],cnt[MAX];
int main()
{
	int T,n,k,i,a,b,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			d[i]=cnt[i]=0;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
			d[a]++;
			d[b]++;
		}
		queue<int> q;
		for(i=1;i<=n;i++)
		{
			if(d[i]==1) q.push(i);
		}
		ans=0;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(auto &to:mp[x])
			{
				if(!d[to]) continue;
				d[to]--;
				d[x]--;
				if(d[x]==0)
				{
					cnt[to]++;
					if(cnt[to]==k)
					{
						cnt[to]-=k;
						ans++;
					}
				}
				if(d[to]==1 && cnt[to]==0) q.push(to);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
这题是不是直接从叶子开始bfs，类似拓扑排序往里缩。
*/
