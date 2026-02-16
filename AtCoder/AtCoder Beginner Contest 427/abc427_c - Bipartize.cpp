#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[12];
int col[12],ans;
void dfs(int x,int n)
{
	if(x==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(auto &to:mp[i])
			{
				if(col[i]==col[to]) cnt++;
			}
		}
		ans=min(ans,cnt/2);
		return;
	}
	col[x]=0;
	dfs(x+1,n);
	col[x]=1;
	dfs(x+1,n);
	col[x]=0;
}
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	ans=INF;
	dfs(1,n);
	printf("%d\n",ans);
	return 0;
}
