#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PIL pair<int,ll>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	int id,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int flag[211],n;
ll dis[211],edge[211][211];
void dijstra(int s)
{
	int i,pre;
	priority_queue<node> q;
	node t;
	mem(dis,0x3f);
	mem(flag,0);
	dis[s]=0;
	t.id=s;
	t.v=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		pre=t.id;
		if(flag[pre]) continue;
		flag[pre]=1;
		for(i=2;i<=n;i++)
		{
			if(edge[pre][i]<LLINF&&dis[i]>max(dis[pre],edge[pre][i]))
			{
				dis[i]=max(dis[pre],edge[pre][i]);
				t.id=i;
				t.v=dis[i];
				q.push(t);
			}
		}
	}
}
ll x[222],y[222];
ll dist(int i,int j)
{
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
int main()
{
	int i,j;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&x[i],&y[i]);
		}
		mem(edge,0x3f);
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				edge[i][j]=edge[j][i]=dist(i,j);
			}
		}
		dijstra(1);
		printf("%.6lf\n",sqrt(dis[2]));
	}
	return 0;
}