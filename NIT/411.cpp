#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const int mod=100000007;
vector<PII > mp[MAX];
int flag[MAX],dis[MAX],cnt[MAX];
struct node
{
	int id,v;
	node(){}
	node(int a,int b) :id(a),v(b){}
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
void dijkstra(int s)
{
	int i,sz;
	priority_queue<node> q;
	node t;
	PII to;
	mem(dis,0x3f);
	mem(cnt,0);
	mem(flag,0);
	dis[s]=0;
	cnt[s]=1;
	q.push(node(s,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		sz=sz(mp[t.id]);
		for(i=0;i<sz;i++)
		{
			to=mp[t.id][i];
			if(dis[to.fi]>dis[t.id]+to.se)
			{
				cnt[to.fi]=cnt[t.id];
				dis[to.fi]=dis[t.id]+to.se;
				q.push(node(to.fi,dis[to.fi]));
			}
			else if(dis[to.fi]==dis[t.id]+to.se)
			{
				cnt[to.fi]+=cnt[t.id];
				cnt[to.fi]%=mod;
				q.push(node(to.fi,dis[to.fi]));
			}
		}
	}
}
int n,m;
void spfa(int s)
{
	int i,sz;
	queue<node> q;
	node t;
	PII to;
	mem(dis,0x3f);
	mem(cnt,0);
	mem(flag,0);
	dis[s]=0;
	cnt[s]=1;
	flag[s]=1;
	q.push(node(s,0));
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t.id]=0;
		if(t.id==n*m+1) continue;
		for(i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			if(dis[to.fi]>dis[t.id]+to.se)
			{
				dis[to.fi]=dis[t.id]+to.se;
				cnt[to.fi]=cnt[t.id];
				if(!flag[to.fi])
				{
					q.push(node(to.fi,dis[to.fi]));
					flag[to.fi]=1;
				}
			}
			else if(dis[to.fi]==dis[t.id]+to.se)
			{
				cnt[to.fi]+=cnt[t.id];
				cnt[to.fi]%=mod;
				if(!flag[to.fi])
				{
					q.push(node(to.fi,dis[to.fi]));
					flag[to.fi]=1;
				}
			}
		}
		cnt[t.id]=0;
	}
}
int a[555][555];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int check(int x,int y)
{
	if(x<1||y<1||x>n||y>m||a[x][y]==-1) return 0;
	return 1;
}
int getid(int x,int y)
{
	return m*(x-1)+y;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,j,k,x,y,xx,yy;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<=n*m+1;i++) mp[i].clear();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]==-1) continue;
				xx=getid(i,j);
				for(k=0;k<4;k++)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					if(!check(x,y)) continue;
					yy=getid(x,y);
	//				cout<<xx<<" "<<yy<<" "<<a[x][y]<<endl;
					mp[xx].pb(MP(yy,a[x][y]));
				}
			}
		}
		for(i=1;i<=m;i++)
		{
			if(a[1][i]!=-1) mp[0].pb(MP(i,a[1][i]));
		}
		for(i=m*(n-1)+1,j=1;j<=m;i++,j++)
		{
			if(a[n][j]!=-1) mp[i].pb(MP(n*m+1,0));
		}
	/*	for(i=0;i<=n*m+1;i++)
		{
			for(j=0;j<sz(mp[i]);j++)
			{
				cout<<i<<" "<<mp[i][j].fi<<" "<<mp[i][j].se<<endl;
			}
			puts("***");
		} */
		dijkstra(0);
	//	spfa(0);
		if(dis[n*m+1]==INF) puts("-1");
		else printf("%d %d\n",dis[n*m+1],cnt[n*m+1]);
	}
	return 0;
}
/*
5 5
1 2 1 1 1
1 1 1 1 1
3 1 -1 2 2
1 2 1 2 2
1 1 1 1 1
*/