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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct High_Level_Preflow_Push
{
	static const int N=30010;
	struct node{int v,cap,index;};
	vector<node> edge[N];
	vector<int> List[N];
	vector<list<int>::iterator> listit;
	list<int> dlist[N];
	int highest,highestActive,vis[N],excess[N],height[N],n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) edge[i].clear();
	}
	void add(int u,int v,int cap)
	{
		edge[u].push_back(node{v,cap,edge[v].size()});
		edge[v].push_back(node{u,0,edge[u].size()-1});
	}
	void globalRelabel(int t)
	{
		int u,i,hp,v,index;
		queue<int> q;
		for(i=0;i<=n;i++)
		{
			height[i]=n;
			List[i].clear();
			dlist[i].clear();
			vis[i]=0;
		}
		height[t]=0;
		q.push(t);
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			for(i=0;i<edge[u].size();i++)
			{
				v=edge[u][i].v;
				index=edge[u][i].index;
				if(height[v]==n&&edge[v][index].cap>0)
				{
					height[v]=height[u]+1;
					vis[height[v]]++;
					q.push(hp=v);
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(height[i]<n)
			{
				listit[i]=dlist[height[i]].insert(dlist[height[i]].begin(),i);
				if(excess[i]>0) List[height[i]].push_back(i);
			}
		}
		highest=height[hp];
		highestActive=height[hp];
	}
	void push(int u,node &e)
	{
		int v,df;
		v=e.v;
		df=min(excess[u],e.cap);
		e.cap=e.cap-df;
		edge[v][e.index].cap=edge[v][e.index].cap+df;
		excess[u]=excess[u]-df;
		excess[v]=excess[v]+df;
		if(excess[v]>0&&excess[v]<=df) List[height[v]].push_back(v);
	}
	void discharge(int u)
	{
		int i,nh,v,cap,h;
		nh=n;
		for(i=0;i<edge[u].size();i++)
		{
			v=edge[u][i].v;
			cap=edge[u][i].cap;
			if(cap>0)
			{
				if(height[u]==height[v]+1)
				{
					push(u,edge[u][i]);
					if(excess[u]==0) return;
				}
				else nh=min(nh,height[v]+1);
			}
		}
		h=height[u];
		if(vis[h]==1)
		{
			for(i=h;i<=highest;i++)
			{
				for(list<int>::iterator it=dlist[i].begin();it!=dlist[i].end();it++)
				{
					vis[height[*it]]--;
					height[*it]=n;
				}
				dlist[i].clear();
			}
			highest=h-1;
		}
		else
		{
			vis[h]--;
			listit[u]=dlist[h].erase(listit[u]);
			height[u]=nh;
			if(nh==n) return;
			vis[nh]++;
			listit[u]=dlist[nh].insert(dlist[nh].begin(),u);
			highestActive=nh;
			highest=max(highest,highestActive);
			List[nh].push_back(u);
		}
	}
	int maxflow(int s,int e)
	{
		int i,u;
		if(s==e) return 0;
		highestActive=0;
		highest=0;
		for(i=0;i<=n;i++) height[i]=vis[i]=excess[i]=0;
		height[s]=n;
		listit.resize(n);
		for(i=0;i<n;i++)
		{
			if(i!=s)
			{
				listit[i]=dlist[height[i]].insert(dlist[height[i]].begin(),i);
			}
		}
		vis[0]=n-1;
		excess[s]=INF;
		excess[e]=-INF;
		for(i=0;i<edge[s].size();i++) push(s,edge[s][i]);
		globalRelabel(e);
		while(highestActive>=0)
		{
			if(List[highestActive].empty()==1)
			{
				highestActive--;
				continue;
			}
			u=List[highestActive].back();
			List[highestActive].pop_back();
			discharge(u);
		}
		return excess[e]+INF;
	}
}hlpp;
void go()
{
	int n,m,i,s,t,a,b,w;
	while(~scanf("%d%d",&n,&m))
	{
		s=n+1;
		t=n+2;
		hlpp.init(n+10);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			hlpp.add(s,i,a);
			hlpp.add(i,t,b); 
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&w);
			hlpp.add(a,b,w);
			hlpp.add(b,a,w); 
		}
		printf("%d\n",hlpp.maxflow(s,t));
	}
}

