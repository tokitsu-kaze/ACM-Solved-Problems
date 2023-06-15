#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Disjoint_Set_Union
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
__gnu_pbds::priority_queue<pair<int,int>,
						   greater<pair<int,int>>,
						   pairing_heap_tag> q[MAX];
int flag[MAX];
int main()
{
	int n,m,i,op,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		while(!q[i].empty()) q[i].pop();
		flag[i]=0;
	}
	dsu.init(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		q[i].push({x,i});
	}
	while(m--)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			if(flag[x]||flag[y]) continue;
			x=dsu.find(x);
			y=dsu.find(y);
			dsu.merge(x,y);
			q[dsu.find(x)].join(q[x+y-dsu.find(x)]);
		}
		else
		{
			if(flag[x])
			{
				puts("-1");
				continue;
			}
			x=dsu.find(x);
			printf("%d\n",q[x].top().first);
			flag[q[x].top().second]=1;
			q[x].pop();
		}
	}
	return 0;
}
