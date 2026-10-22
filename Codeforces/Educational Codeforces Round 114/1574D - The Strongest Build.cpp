#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node
{
	int v;
	vector<int> pos;
	friend bool operator<(node x,node y){return x.v<y.v;}
};
int c[12],a[12][MAX];
int main()
{
	int n,m,i,j,now;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		for(j=1;j<=c[i];j++) scanf("%d",&a[i][j]);
	}
	map<vector<int>,int> vis,ban;
	vector<int> tmp(n);
	scanf("%d",&m);
	while(m--)
	{
		for(auto &it:tmp) scanf("%d",&it);
		ban[tmp]=1;
	}
	priority_queue<node> q;
	now=0;
	for(i=0;i<n;i++)
	{
		tmp[i]=c[i];
		now+=a[i][c[i]];
	}
	q.push({now,tmp});
	vis[tmp]=1;
	while(1)
	{
		node t=q.top();
		q.pop();
		if(!ban.count(t.pos))
		{
			for(i=0;i<n;i++) printf("%d%c",t.pos[i]," \n"[i+1==n]);
			break;
		}
		for(i=0;i<n;i++)
		{
			if(t.pos[i]==1) continue;
			node nex=t;
			nex.v-=a[i][nex.pos[i]];
			nex.pos[i]--;
			nex.v+=a[i][nex.pos[i]];
			if(!vis.count(nex.pos))
			{
				vis[nex.pos]=1;
				q.push(nex);
			}
		}
	}
	return 0;
}
