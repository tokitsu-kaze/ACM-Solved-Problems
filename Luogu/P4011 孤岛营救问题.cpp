#include <bits/stdc++.h>
using namespace std;
struct node {int id,v,k;};
vector<int> mp[233];
int dir[4][2]={0,1,1,0,0,-1,-1,0},n,m;
int gate[233][233];
int flag[233][(1<<12)+10],key[233];
int bfs(int x)
{
	int to,i,tmp;
	node t;
	queue<node> q;
	q.push({x,0,key[x]});
	memset(flag,0,sizeof flag);
	flag[x][key[x]]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.id==n*m) return t.v;
		for(auto &to:mp[t.id])
		{
			tmp=gate[t.id][to];
			if(tmp)
			{
				if(tmp&1) continue;//是墙，不能走 
				if((tmp&t.k)!=tmp) continue;//没钥匙，不能走 
			}
			if(flag[to][t.k|key[to]]) continue;
			q.push({to,t.v+1,t.k|key[to]});
			flag[to][t.k|key[to]]=1;
		}
	}
	return -1;
}

int check(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return 0;
	return 1;
}
int getid(int x,int y)
{
	return m*(x-1)+y;
}
int main()
{
	int i,j,k,x,y,xx,yy,p,a,b,c,d,e;
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n*m;i++) mp[i].clear();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			xx=getid(i,j);
			for(k=0;k<4;k++)
			{
				x=i+dir[k][0];
				y=j+dir[k][1];
				if(!check(x,y)) continue;
				yy=getid(x,y);
				mp[xx].push_back(yy);
			}
		}
	}
	memset(gate,0,sizeof gate);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		x=getid(a,b);
		y=getid(c,d);
		gate[x][y]|=1<<e;
		gate[y][x]|=1<<e;
	}
	memset(key,0,sizeof key);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d%d",&a,&b,&c);
		key[getid(a,b)]|=1<<c;
	}
	printf("%d\n",bfs(1));
	return 0;
}
