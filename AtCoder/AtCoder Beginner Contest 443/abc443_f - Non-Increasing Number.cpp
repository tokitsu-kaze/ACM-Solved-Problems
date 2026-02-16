#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e6+10;
struct node{int pos,d,v;}pre[MAX][10];
int vis[MAX][10];
char ans[MAX*10];
int main()
{
	int n,i;
	node t,nex,res;
	scanf("%d",&n);
	memset(vis,0,sizeof vis);
	queue<node> q;
	for(i=1;i<=9;i++)
	{
		if(!vis[i%n][i])
		{
			q.push({1,i,i%n});
			vis[i%n][i]=1;
			pre[i%n][i]={-1,-1,-1};
		}
	}
	res={-1,-1,-1};
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.v==0)
		{
			res=t;
			break;
		}
		for(i=t.d;i<=9;i++)
		{
			nex.pos=t.pos+1;
			nex.d=i;
			nex.v=(t.v*10+i)%n;
			if(!vis[nex.v][nex.d])
			{
				vis[nex.v][nex.d]=1;
				q.push(nex);
				pre[nex.v][nex.d]=t;
			}
		}
	}
	if(res.v==-1)
	{
		puts("-1");
		return 0;
	}
	ans[res.pos+1]='\0';
	while(res.pos>=1)
	{
		ans[res.pos]=res.d+'0';
		res=pre[res.v][res.d];
	}
	puts(ans+1);
	return 0;
}
