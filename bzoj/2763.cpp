#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node
{
	int id,k;
	ll v;
	node(){}
	node(int a,ll b,int _k=0) :id(a),v(b),k(_k){}
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
vector<node> mp[MAX];
ll dis[MAX][12];
bool flag[MAX][12];
int n,m,k;
void dij(int s)
{
	int i,sz;
	priority_queue<node> q;
	node t,to;
	mem(dis,0x3f);
	mem(flag,0);
	dis[s][0]=0;
	q.push(node(s,0,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id][t.k]) continue;
		flag[t.id][t.k]=1;
		sz=sz(mp[t.id]);
		for(i=0;i<sz;i++)
		{
			to=mp[t.id][i];
			if(dis[to.id][t.k]>dis[t.id][t.k]+to.v)
			{
				dis[to.id][t.k]=dis[t.id][t.k]+to.v;
				q.push(node(to.id,dis[to.id][t.k],t.k));
			}
			if(t.k<k&&dis[to.id][t.k+1]>dis[t.id][t.k])
			{
				dis[to.id][t.k+1]=dis[t.id][t.k];
				q.push(node(to.id,dis[to.id][t.k+1],t.k+1));
			}
		}
	}
}
void go()
{
	int i,a,b,s,t;
	ll v;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		scanf("%d%d",&s,&t);
		for(i=1;i<=n;i++) mp[i].clear();
		while(m--)
		{
			scanf("%d%d%lld",&a,&b,&v);
			mp[a].pb(node(b,v));
			mp[b].pb(node(a,v));
		}
		dij(s);
		ll ans=LLINF;
		for(i=0;i<=k;i++) ans=min(ans,dis[t][i]);
		printf("%lld\n",ans);
	}
}
