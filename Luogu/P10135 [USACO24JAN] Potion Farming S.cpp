#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
set<pair<int,int>> s[MAX];
int tag[MAX],ans;
void dfs(int x,int fa,int h)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,h+1);
		if(s[to].size()>s[x].size()) swap(s[to],s[x]);
		for(auto &it:s[to]) s[x].insert(it);
	}
	if(x!=1&&mp[x].size()==1) s[x].insert({h,x});
	while(tag[x]>0&&s[x].size()>0)
	{
		tag[x]--;
		ans++;
		s[x].erase(*s[x].rbegin());
	}
}
int v[MAX];
int main()
{
	int n,i,a,b,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		mp[i].clear();
		s[i].clear();
		tag[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	cnt=0;
	for(i=2;i<=n;i++)
	{
		if(mp[i].size()==1) cnt++;
	}
	for(i=1;i<=cnt;i++) tag[v[i]]++;
	ans=0;
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
