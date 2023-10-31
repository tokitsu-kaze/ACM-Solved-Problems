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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
struct node
{
	int n,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int mp[1111][1111];
int flag[1111],n;
node bfs(int s)
{
	int i;
	node t,next,res;
	priority_queue<node> q;
	mem(flag,0);
	t.n=s;
	t.v=1;
	flag[s]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		res=t;
		for(i=0;i<n;i++)
		{
			if(!flag[i]&&mp[t.n][i])
			{
				next.v=t.v+1;
				next.n=i;
				flag[i]=1;
				q.push(next);
			}
		}
	}
	return res;
}
int main()
{
	int m,a,b,ans,cnt;
	node res;
	while(~scanf("%d%d",&n,&m))
	{
		ans=7;
		mem(mp,0);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a][b]=mp[b][a]=1;
		}
		res=bfs(0);
		res=bfs(res.n);
		if(res.v<=7) puts("Impossible");
		else printf("%d\n",res.v);
	}
	return 0;
}