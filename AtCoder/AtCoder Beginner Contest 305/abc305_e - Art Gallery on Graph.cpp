#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node
{
	int x,v;
	friend bool operator < (node x,node y)
	{
		return x.v<y.v;
	}
};
vector<int> mp[MAX],res;
int mx[MAX],tag[MAX],n,m,k;
void bfs()
{
	int i,p,h;
	priority_queue<node> q;
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&p,&h);
		mx[p]=h;
		q.push({p,h});
	}
	res.clear();
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		tag[t.x]=1;
		if(t.v==0) continue;
		for(auto &to:mp[t.x])
		{
			if(mx[to]>=t.v-1) continue;
			mx[to]=t.v-1;
			q.push({to,mx[to]});
		}
	}
	for(i=1;i<=n;i++)
	{
		if(tag[i]) res.push_back(i);
	}
	printf("%d\n",(int)res.size());
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==(int)res.size()]);
}
int main()
{
	int i,a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		mx[i]=-1;
		tag[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	bfs();
	return 0;
}
