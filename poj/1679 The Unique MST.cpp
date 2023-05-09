#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
int n,pre[1111];
int mp[1111][1111],maxx[1111][1111],dis[1111];
bool used[1111][1111],flag[1111];
struct node
{
	int n;
	double v;
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
void init()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		dis[i]=INF;
		pre[i]=1;
		for(j=1;j<=n;j++)
		{
			mp[i][j]=INF;
		}
	}
	mem(maxx,0);
	mem(used,0);
	mem(flag,0);
}
int prim()
{
	int i,cnt=0;
	double ans=0;
	priority_queue<node>q;
	node t,next;
	t.n=1;
	t.v=0;
	dis[1]=0;
	pre[1]=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.n]) continue;
		flag[t.n]=1;
		used[t.n][pre[t.n]]=used[pre[t.n]][t.n]=1;
		ans+=t.v;
		cnt++;
		for(i=1;i<=n;i++)
		{
			if(flag[i]&&i!=t.n)
			{
				maxx[t.n][i]=maxx[i][t.n]=max(maxx[i][pre[t.n]],dis[t.n]);
			}
			if(!flag[i]&&dis[i]>mp[t.n][i])
			{
				dis[i]=mp[t.n][i];
				next.n=i;
				next.v=dis[i];
				pre[i]=t.n;
				q.push(next);
			}
		}
	}
	if(cnt!=n) return -1;
	else return ans;
}
int smst(int v)
{
	int i,j,res=INF;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(mp[i][j]!=INF&&!used[i][j])
			{
				res=min(res,v+mp[i][j]-maxx[i][j]);
			}
		}
	}
	if(res==INF) return -1;
	else return res;
}
int main()
{
	int t,m,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init();
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[a][b]=mp[b][a]=c;
		}
		int ans=prim();
		if(ans==-1)
		{
			puts("Not Unique!");
			continue;
		}
		if(smst(ans)==ans) puts("Not Unique!");
		else printf("%d\n",ans);
	}
	return 0;
}