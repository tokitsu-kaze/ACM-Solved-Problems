#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
const int mod=1e9+7;
unordered_set<int> mp[MAX];
ll sum[MAX];
int v[MAX];
const int LIMT=400;
int main()
{
	int n,m,i,a,b,op,x,y,q;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		sum[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(mp[a].size()<=LIMT) mp[a].insert(b);
		else mp[b].insert(a);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		for(auto &to:mp[i]) sum[to]+=v[i];
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			if(mp[x].count(y))
			{
				sum[y]-=v[x];
				mp[x].erase(y);
			}
			else if(mp[y].count(x))
			{
				sum[x]-=v[y];
				mp[y].erase(x);
			}
			else
			{
				if(mp[x].size()<=LIMT)
				{
					mp[x].insert(y);
					sum[y]+=v[x];
				}
				else
				{
					mp[y].insert(x);
					sum[x]+=v[y];
				}
			}
		}
		else if(op==2)
		{
			scanf("%d%d",&x,&y);
			for(auto &to:mp[x]) sum[to]+=y-v[x];
			v[x]=y;
		}
		else
		{
			scanf("%d",&x);
			ans=sum[x];
			for(auto &to:mp[x]) ans+=v[to];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
