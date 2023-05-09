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
const double eps=1e-8;
const int MAX=2e3+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node
{
	int id;
	int v;
	node(){}
	node(int a,int b) :id(a),v(b){}
	friend bool operator <(node a,node b){return a.v>b.v;}
};
vector<node> mp[MAX];
bool flag[MAX];
int dis[MAX],ans;
void prim()
{
	node t,to;
	priority_queue<node> q;
	mem(dis,0x3f);
	mem(flag,0);
	dis[1]=0;
	q.push(node(1,dis[1]));
	ans=0;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		ans+=dis[t.id];
		for(int i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			if(!flag[to.id]&&dis[to.id]>to.v)
			{
				dis[to.id]=to.v;
				q.push(node(to.id,dis[to.id]));
			}
		}
	}
}
void go()
{
	int n,i,j,x;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			for(j=1;j<=n;j++)
			{
				scanf("%d",&x);
				if(x) mp[i].pb(node(j,x));
			}
		}
		prim();
		printf("%d\n",ans);
	}
}
