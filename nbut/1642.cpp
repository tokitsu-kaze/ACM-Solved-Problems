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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int n,m,sx,sy,ex,ey,t1,t2,flag1,a[511][511],flag[511][511],ans1,ans2,dir[4][2]={0,1,0,-1,1,0,-1,0};
int flag2[511][511][5];
struct xy
{
	int x,y,v,pre;
	friend bool operator<(xy a,xy b)
	{
		return a.v>b.v;
	}
};
int check(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!=-1&&!flag[x][y]) return 1;
	return 0;
}
int bfs1(int x,int y)
{
	int i;
	mem(flag,0);
	xy t,next;
	priority_queue<xy> q;
	t.x=x;
	t.y=y;
	t.v=a[x][y];
	q.push(t);
	flag[x][y]=1;
	while(!q.empty())
	{
		t=q.top();
		if(t.x==ex&&t.y==ey) return t.v;
		q.pop();
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				flag[next.x][next.y]=1;
				next.v=t.v+a[next.x][next.y];
				q.push(next);
			}
		}
	}
	return -1;
}
int bfs2(int x,int y)
{
	int i;
	mem(flag,0);
	mem(flag2,0);
	xy t,next;
	priority_queue<xy> q;
	t.x=x;
	t.y=y;
	t.v=a[x][y];
	t.pre=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		if(t.x==ex&&t.y==ey) return t.v;
		q.pop();
		if(!flag2[t.x+1][t.y][1]&&check(t.x+1,t.y)&&t.pre!=1)
		{
			next.x=t.x+1;
			next.y=t.y;
			next.v=t.v+a[next.x][next.y];
			next.pre=1;
			flag2[next.x][next.y][1]=1;
			q.push(next);
		}
		if(!flag2[t.x-1][t.y][2]&&check(t.x-1,t.y)&&t.pre!=2)
		{
			next.x=t.x-1;
			next.y=t.y;
			next.v=t.v+a[next.x][next.y];
			next.pre=2;
			flag2[next.x][next.y][2]=1;
			q.push(next);
		}
		if(!flag2[t.x][t.y+1][3]&&check(t.x,t.y+1)&&t.pre!=3)
		{
			next.x=t.x;
			next.y=t.y+1;
			next.v=t.v+a[next.x][next.y];
			next.pre=3;
			flag2[next.x][next.y][3]=1;
			q.push(next);
		}
		if(!flag2[t.x][t.y-1][4]&&check(t.x,t.y-1)&&t.pre!=4)
		{
			next.x=t.x;
			next.y=t.y-1;
			next.v=t.v+a[next.x][next.y];
			next.pre=4;
			flag2[next.x][next.y][4]=1;
			q.push(next);
		}
	}
	return -1;
}
/*void dfs1(int x,int y)
{
	int i,tx,ty;
	if(x==ex&&y==ey)
	{
		ans1=min(ans1,t1);
		return;
	}
	for(i=0;i<4;i++)
	{
		tx=x+dir[i][0];
		ty=y+dir[i][1]; 
		if(check(tx,ty))
		{
			t1+=a[tx][ty];
			flag[tx][ty]=1;
			dfs1(tx,ty);
			t1-=a[tx][ty];
			flag[tx][ty]=0;
		}
	}
}
void dfs2(int x,int y,int pre)
{
	int i,tx,ty,tp;
	tp=pre;
	if(x==ex&&y==ey)
	{
		ans2=min(ans2,t2);
		return;
	}
	if(tp==1)
	{
		for(i=0;i<2;i++)
		{
			tx=x+dir[i][0];
			ty=y+dir[i][1]; 
			if(check(tx,ty))
			{
				t2+=a[tx][ty];
		//		flag[tx][ty]=1;
				tp=-1;
				dfs2(tx,ty,tp);
				t2-=a[tx][ty];
		//		flag[tx][ty]=0;
				tp=pre;
			}
		}
	}
	else if(tp==-1)
	{
		for(i=2;i<4;i++)
		{
			tx=x+dir[i][0];
			ty=y+dir[i][1]; 
			if(check(tx,ty))
			{
				t2+=a[tx][ty];
		//		flag[tx][ty]=1;
				tp=1;
				dfs2(tx,ty,tp);
				t2-=a[tx][ty];
		//		flag[tx][ty]=0;
				tp=pre;
			}
		}
	}
	else if(tp==0)
	{
		for(i=0;i<4;i++)
		{
			tx=x+dir[i][0];
			ty=y+dir[i][1]; 
			if(check(tx,ty))
			{
				t2+=a[tx][ty];
		//		flag[tx][ty]=1;
				if(i==0||i==1) tp=-1;
				else tp=1;
				dfs2(tx,ty,tp);
				t2-=a[tx][ty];
		//		flag[tx][ty]=0;
				tp=pre;
			}
		}
	}
	return;
}*/
int main()
{
	int cas=1,i,j;
	char temp[5];
	while(cin>>n>>m>>sx>>sy>>ex>>ey)
	{
		mem(a,0);
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%s",temp);
				if(temp[0]=='*') a[i][j]=-1;
				else a[i][j]=atoi(temp);
			}
		}
	/*	for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cout<<a[i][j]<<" ";
			}
			puts("");
		}*/
	/*	ans1=ans2=INF;
		t1=t2=a[sx][sy];
		mem(flag,0);
		flag[sx][sy]=1;
		dfs1(sx,sy);
		mem(flag,0);
		flag[sx][sy]=1;
		dfs2(sx,sy,0);
		if(ans1==INF) ans1=-1;
		if(ans2==INF) ans2=-1;*/
		printf("Case %d: %d %d\n",cas++,bfs1(sx,sy),bfs2(sx,sy));
		
	}
    return 0;
}