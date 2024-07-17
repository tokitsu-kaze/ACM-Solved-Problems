#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
vector<int> mp[MAX];
multiset<int> s[MAX];
int a[MAX],b[MAX],m;
ll ans,now[MAX];
void dfs(int x)
{
	now[x]=a[x];
	s[x].insert(a[x]);
	for(auto &to:mp[x])
	{
		dfs(to);
		if(s[to].size()>s[x].size()) swap(s[to],s[x]);
		s[x].insert(s[to].begin(),s[to].end());
		now[x]+=now[to];
	}
	while(now[x]>m)
	{
		now[x]-=*s[x].rbegin();
		s[x].erase(s[x].find(*s[x].rbegin()));
	}
	ans=max(ans,1LL*b[x]*(ll)s[x].size());
}
int main()
{
	int n,i,fa;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		s[i].clear();
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&fa,&a[i],&b[i]);
		if(fa) mp[fa].push_back(i);
	}
	ans=0;
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
