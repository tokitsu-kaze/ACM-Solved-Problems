#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e4+10;
const ll mod=1e9+7;
const int sz=3;
int x[MAX],y[MAX],k,n,m,cost[MAX];
bool flag[MAX];
struct node
{
	int x,y,v,id;
	node(){}
	node(int a,int b,int c,int d)
	{
		x=a;
		y=b;
		v=c;
		id=d;
	}
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int bfs()
{
	int i;
	priority_queue<node> q;
	node t;
	q.push(node(1,1,0,1));
	cost[1]=0;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.x>=n&&t.y>=m) return t.v;
		if(flag[t.id]) continue;
		flag[t.id]=1;
		for(i=1;i<=k;i++)
		{
			if(flag[i]) continue;
			if((abs(x[i]-t.x)==1&&y[i]==t.y)||(abs(y[i]-t.y)==1&&x[i]==t.x))
			{
				if(cost[i]>t.v)
				{
					cost[i]=t.v;
					q.push(node(x[i],y[i],t.v,i));
				}
			}
			else if(abs(x[i]-t.x)<=2||abs(y[i]-t.y)<=2)
			{
				if(cost[i]>t.v+1)
				{
					cost[i]=t.v+1;
					q.push(node(x[i],y[i],t.v+1,i));
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,tag;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		tag=0;
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			if(x[i]==n&&y[i]==m) tag=1;
		}
		if(!tag)
		{
			k++;
			x[k]=n+1;
			y[k]=m+1;
		}
		mem(flag,0);
		mem(cost,0x3f);
		printf("%d\n",bfs());
	}
	return 0;
}