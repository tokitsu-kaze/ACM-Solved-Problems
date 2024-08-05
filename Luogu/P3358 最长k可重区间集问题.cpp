#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=505;
struct Discretization
{
	#define type int
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct MCMF_dij
{
	#define type int
	#define inf INF
	#define PTI pair<type,int>
	static const int N=1000+10;
	struct node
	{
		int from,to;
		type flow,cost;
		node(){}
		node(int u,int v,type f,type co):from(u),to(v),flow(f),cost(co){}
	};
	int n,s,t,id[N],vis[N];
	vector<node> edge;
	vector<int> mp[N];
	type dis[N],h[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		edge.clear();
	}
	void add_edge(int from,int to,type cap,type cost=0)
	{
		edge.push_back(node(from,to,cap,cost));
		edge.push_back(node(to,from,0,-cost));
		int m=edge.size();
		mp[from].push_back(m-2);
		mp[to].push_back(m-1);
	}
	void spfa()
	{
		int i,x,to;
		for(i=0;i<=n;i++)
		{
			h[i]=inf;
			vis[i]=0;
		}
		queue<int> q;
		q.push(s);
		h[s]=0;
		vis[s]=1;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			vis[x]=0;
			for(i=0;i<mp[x].size();i++)
			{
				node &e=edge[mp[x][i]];
				to=e.to;
				if(e.flow>0&&h[to]>h[x]+e.cost)
				{ 
					h[to]=h[x]+e.cost;
					if(!vis[to])
					{
						vis[to]=1;
						q.push(to);
					}
				}
			}
		}
	}
	bool dij()
	{
		int i,x,to;
		type cost,now_cost;
		for(i=0;i<=n;i++) dis[i]=inf;
		dis[s]=0;id[s]=0;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		q.push({type(0),s});
		while(!q.empty())
		{
			PTI tmp=q.top();
			q.pop();
			cost=tmp.first;
			x=tmp.second;
			if(cost>dis[x]) continue;
			for(i=0;i<mp[x].size();i++)
			{
				node& e=edge[mp[x][i]];
				to=e.to;
				type now_cost=e.cost+h[x]-h[to];
				if(e.flow>0&&dis[to]>dis[x]+now_cost)
				{ 
					dis[to]=dis[x]+now_cost;
					q.push({dis[to],to});
					e.from=x;
					id[to]=mp[x][i];
				}
			}
		}
		return dis[t]!=inf;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		int i;
		type flow=0,cost=0;
		s=_s;
		t=_t;
		spfa();
		while(dij())
		{
			for(i=0;i<=n;i++) h[i]+=dis[i];
			type new_flow=inf;
			for(i=t;i!=s;i=edge[id[i]].from)
			{
				new_flow=min(new_flow,edge[id[i]].flow);
			}
			for(i=t;i!=s;i=edge[id[i]].from)
			{
				edge[id[i]].flow-=new_flow;
				edge[id[i]^1].flow+=new_flow;
			}
			flow+=new_flow;
			cost+=new_flow*h[t];
		}
		return {cost,flow};
	}
	#undef type
	#undef inf
	#undef PTI
}mcmf; // upper: O(nm + max_flow*mlogm)
int l[MAX],r[MAX];
int main()
{
	int n,k,i,s,t,len;
	scanf("%d%d",&n,&k);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		d.add(l[i]);
		d.add(r[i]);
	}
	d.work();
	s=d.size()+1;
	t=s+1;
	mcmf.init(t);
	mcmf.add_edge(s,1,k,0);
	mcmf.add_edge(d.size(),t,INF,0);
	for(i=1;i<d.size();i++) mcmf.add_edge(i,i+1,INF,0);
	for(i=1;i<=n;i++)
	{
		len=r[i]-l[i];
		l[i]=d.get_pos(l[i]);
		r[i]=d.get_pos(r[i]);
		mcmf.add_edge(l[i],r[i],1,-len);
	}
	printf("%d\n",-mcmf.mincost_maxflow(s,t).first);
	return 0;
}
