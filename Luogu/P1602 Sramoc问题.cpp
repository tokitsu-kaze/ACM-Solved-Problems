#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int now;
	string v;
};
int vis[1010][11];
void bfs(int k,int m)
{
	int i;
	node t,nex;
	memset(vis,0,sizeof vis);
	queue<node> q;
	for(i=1;i<=k-1;i++)
	{
		q.push({i%m,to_string(i)});
		vis[i%m][i]=1;
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.now==0)
		{
			cout<<t.v<<"\n";
			return;
		}
		for(i=0;i<=k-1;i++)
		{
			nex.now=(t.now*10+i)%m;
			if(vis[nex.now][i]) continue;
			nex.v=t.v+to_string(i);
			vis[nex.now][i]=1;
			q.push(nex);
		}
	}
}
int main()
{
	int k,m;
	scanf("%d%d",&k,&m);
	bfs(k,m);
	return 0;
}
