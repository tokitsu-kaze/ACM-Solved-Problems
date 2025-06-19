#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
struct node
{
	int d,x,y;
	friend bool operator <(node a,node b)
	{
		return a.d>b.d;
	}
};
int x[MAX],y[MAX];
int cal(int i,int j)
{
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int main()
{
	int n,q,i,j,op,a,b,now;
	node t,tmp;
	scanf("%d%d",&n,&q);
	dsu.init(n+q);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	priority_queue<node> pq;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++) pq.push({cal(i,j),i,j});
	}
	now=n;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			n++;
			now++;
			scanf("%d%d",&x[n],&y[n]);
			for(i=1;i<n;i++) pq.push({cal(i,n),i,n});
		}
		else if(op==2)
		{
			if(now==1)
			{
				puts("-1");
				continue;
			}
			while(1)
			{
				t=pq.top();
				pq.pop();
				if(!dsu.merge(t.x,t.y)) continue;
				now--;
				printf("%d\n",t.d);
				break;
			}
			tmp=t;
			while(!pq.empty())
			{
				t=pq.top();
				pq.pop();
				if(t.d==tmp.d) now-=dsu.merge(t.x,t.y);
				else
				{
					pq.push(t);
					break;
				}
			}
		}
		else if(op==3)
		{
			scanf("%d%d",&a,&b);
			if(dsu.find(a)==dsu.find(b)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
