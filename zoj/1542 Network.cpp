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
const int MAX=2e3+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct dsu
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
struct node
{
	int x,y,w;
	node(){}
	node(int a,int b,int c):x(a),y(b),w(c){}
	friend bool operator<(node a,node b) {return a.w<b.w;}
};
vector<node> edge;
VI ans;
int kruskal(int n)
{
	int res=0;
	dsu.init(n);
	sort(all(edge));
	for(int i=0;i<sz(edge);i++)
	{
		if(dsu.merge(edge[i].x,edge[i].y))
		{
			res=max(res,edge[i].w);
			ans.pb(i);
		}
	}
	return res;
}
void go()
{
	int n,m,i,a,b,w;
	while(~scanf("%d%d",&n,&m))
	{
		edge.clear();
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&w);
			edge.pb(node(a,b,w));
		}
		ans.clear();
		printf("%d\n",kruskal(n));
		printf("%d\n",sz(ans));
		for(i=0;i<sz(ans);i++) printf("%d %d\n",edge[ans[i]].x,edge[ans[i]].y);
	}
}
