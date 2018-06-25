////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-04 19:35:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6181
////Problem Title: 
////Run result: Accept
////Run time:561MS
////Run memory:14844KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=10007;
struct node
{
	int id;
	ll v;
	node(){}
	node(int a,ll b)
	{
		id=a;
		v=b;
	}
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
ll dis[MAX],dis2[MAX];
vector<node> mp[MAX];
void dijkstra(int s)
{
	int i,pre;
	priority_queue<node> q;
	node t,to;
	mem(dis,0x3f);
	mem(dis2,0x3f);
	dis[s]=0;
	q.push(node(s,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.v>dis2[t.id]) continue;
		for(i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			ll d=t.v+to.v;
			if(dis[to.id]>d)
			{
				swap(dis[to.id],d); 
				q.push(node(to.id,dis[to.id]));
			}
			if(dis[to.id]<d&&dis2[to.id]>d)
			{
				dis2[to.id]=d;
				q.push(node(to.id,dis2[to.id]));
			}
		}
	}
}
int main()
{
	int t,n,m,a,b,i;
	ll v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		while(m--)
		{
			scanf("%d%d%lld",&a,&b,&v);
			mp[a].pb(node(b,v));
			mp[b].pb(node(a,v));
		}
		dijkstra(1);
		printf("%lld\n",dis2[n]);
	}
	return 0;
}