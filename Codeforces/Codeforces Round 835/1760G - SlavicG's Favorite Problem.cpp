#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct node{int x,w;};
vector<node> mp[MAX];
int flag[MAX],n,ra[MAX],rb[MAX];
void bfs(int s,int *res,int ban)
{
	int i;
	for(i=1;i<=n;i++) flag[i]=res[i]=0;
	queue<node> q;
	q.push({s,0});
	flag[s]=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		res[t.x]=t.w;
		if(t.x==ban) continue;
		for(auto &it:mp[t.x])
		{
			if(flag[it.x]) continue;
			q.push({it.x,t.w^it.w});
			flag[it.x]=1;
		}
	}
}
int main()
{
	int T,s,t,i,a,b,c,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&s,&t);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[a].push_back({b,c});
			mp[b].push_back({a,c});
		}
		bfs(s,ra,t);
		bfs(t,rb,0);
		map<int,int> ha;
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(i==t) continue;
			if(rb[i]==0) ok=1;
			ha[rb[i]]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(i==t) continue;
			if(ha.count(ra[i])) ok=1;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
