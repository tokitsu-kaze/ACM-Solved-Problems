#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
vector<int> mp[MAX];
map<int,int> s[MAX];
int col[MAX];
ll ans;
void dfs(int x,int fa)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		if(s[to].count(col[x])) ans+=s[to][col[x]];
		if(s[to].size()>s[x].size()) swap(s[to],s[x]);
		for(auto &it:s[to])
		{
			if(it.first==col[x]) continue;
			ans+=1LL*it.second*s[x][it.first];
			s[x][it.first]+=it.second;
		}
	}
	s[x][col[x]]=1;
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&col[i]);
			mp[i].clear();
			s[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		ans=0;
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
