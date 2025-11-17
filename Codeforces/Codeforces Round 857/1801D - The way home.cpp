#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=800+10;
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id,mx;
		type now,cnt;
		friend bool operator <(node a,node b)
		{
			if(a.cnt==b.cnt) return a.now<b.now;
			return a.cnt>b.cnt;
		}
	};
	static const int N=MAX;
	vector<node> mp[N];
	type v[N];
	node dis[N][N];
	int n,vis[N][N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,0,v,0});}
	int ck(node a,node b)
	{
		if(a.cnt==b.cnt) return a.now>b.now;
		return a.cnt<b.cnt;
	}
	ll work(int s,int p)
	{
		int i,j,to;
		type w,cnt;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				dis[i][j]={0,0,0,inf};
				vis[i][j]=0;
			}
		}
		dis[s][s]={s,s,p,0};
		q.push({s,s,p,0});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
//			cout<<"t: "<<t.id<<" "<<t.now<<" "<<t.cnt<<" "<<t.mx<<endl;
			if(vis[t.id][t.mx]) continue;
			vis[t.id][t.mx]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.now;
				node nex;
				cnt=max(0LL,(w-t.now+v[t.mx]-1)/v[t.mx]);
				nex.now=t.now+cnt*v[t.mx]-w;
				nex.cnt=t.cnt+cnt;
				nex.id=to;
				if(v[to]>v[t.mx]) nex.mx=to;
				else nex.mx=t.mx;
//				cout<<"nex: "<<nex.id<<" "<<nex.now<<" "<<nex.cnt<<" "<<nex.mx<<endl;
				if(ck(nex,dis[to][nex.mx]))
				{
					dis[to][nex.mx]=nex;
					if(!vis[to][nex.mx]) q.push(nex);
				}
			}
		}
		type ans=inf;
		for(i=1;i<=n;i++) ans=min(ans,dis[n][i].cnt);
		if(ans==inf) ans=-1;
		return ans;
	}
	#undef type
}dij;
int main()
{
	int T,n,m,p,i,a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&p);
		dij.init(n);
		for(i=1;i<=n;i++) scanf("%lld",&dij.v[i]);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			dij.add_edge(a,b,c);
		}
		printf("%lld\n",dij.work(1,p));
	}
	return 0;
}
