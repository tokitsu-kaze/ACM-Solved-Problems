#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct node{int x,v;};
vector<node> mp[MAX];
int flag[MAX],ok;
ll w[MAX];
void dfs(int x,int fa,ll s)
{
	if(flag[x])
	{
		if(s-w[x]) ok=0;
		return;
	}
	flag[x]=1;
	w[x]=s;
	for(auto &it:mp[x])
	{
		if(it.x==fa) continue;
		dfs(it.x,x,s+it.v);
	}
}
int main()
{
	int t,n,m,i,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			flag[i]=0;
		}
		map<pair<int,int>,int> ha;
		ok=1;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[a].push_back({b,c});
			mp[b].push_back({a,-c});
			if(a>b)
			{
				swap(a,b);
				c=-c;
			}
			if(ha.count({a,b})&&ha[{a,b}]!=c) ok=0;
			ha[{a,b}]=c;
		}
		for(i=1;i<=n;i++)
		{
			if(flag[i]) continue;
			dfs(i,0,0);
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
