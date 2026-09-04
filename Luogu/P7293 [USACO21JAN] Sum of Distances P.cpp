#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
vector<int> mp[MAX],res[3][MAX];
int dis[MAX][2],mx;
void bfs(int n,int s)
{
	int i,x,f;
	for(i=1;i<=n;i++) memset(dis[i],0x3f,sizeof dis[i]);
	dis[s][0]=0;
	queue<pair<int,int>> q;
	q.push({s,0});
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		x=t.first;
		f=t.second;
		for(auto &to:mp[x])
		{
			if(dis[to][!f]>dis[x][f]+1)
			{
				dis[to][!f]=dis[x][f]+1;
				q.push({to,!f});
			}
		}
	}
}
int cnt[MAX],k;
ll inv[MAX];
void init_inv(int n,ll p)
{
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
}
ll work(vector<int> *g)
{
	int i,s;
	ll ans,now;
	for(i=1;i<=k;i++) cnt[i]=0;
	ans=0;
	now=1;
	s=0;
	for(i=0;i<=mx;i++)
	{
		for(auto &id:g[i])
		{
			if(cnt[id]) now=now*inv[cnt[id]]%mod;
			else s++;
			if(s==k) ans=(ans+now*i)%mod;
			cnt[id]++;
			now=now*cnt[id]%mod;
		}
	}
	return ans;
}
int main()
{
	int id,n,m,i,j,a,b;
	for(i=0;i<3;i++)
	{
		for(j=0;j<MAX;j++) res[i][j].clear();
	}
	init_inv(MAX-1,mod);
	scanf("%d",&k);
	mx=0;
	for(id=1;id<=k;id++)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		bfs(n,1);
		for(i=1;i<=n;i++)
		{
			if(dis[i][0]<INF)
			{
				res[0][dis[i][0]].push_back(id);
				mx=max(mx,dis[i][0]);
			}
			if(dis[i][1]<INF)
			{
				res[1][dis[i][1]].push_back(id);
				mx=max(mx,dis[i][1]);
			}
			if(dis[i][0]!=INF && dis[i][1]!=INF)
			{
				res[2][max(dis[i][0],dis[i][1])].push_back(id);
			}
		}
	}
	assert(mx<MAX);
	printf("%lld\n",(work(res[0])+work(res[1])-work(res[2])+mod)%mod);
	return 0;
}
/*
新图说人话就是，每张图都从1开始同时走。
对于一张图，可以在某条边反复横跳，所以分奇偶考虑。
先跑一个从每张图的1号点为起点的最短路。
对于新图的一个节点，距离为 min(max{所有点奇最短路}, max{偶最短路})。
min套max不好处理，利用min(a,b)+max(a,b)=a+b，转化一下变为：
max{偶}+max{奇}-max{max(偶，奇)}，分三部分计算答案。
从小到大枚举每个点作为最大值，方案数就是从其他图各选一个<=最大值并且已经被计算过的点。
维护每张图所有已经被计算过的点的数量的乘积。维护方法有点像 abc411_e 我的做法。
*/
