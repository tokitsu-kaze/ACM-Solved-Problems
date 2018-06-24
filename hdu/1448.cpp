////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-17 00:46:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1448
////Problem Title: 
////Run result: Accept
////Run time:858MS
////Run memory:8688KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=10000+10;
const ll mod=1e6;
int dir[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
int n,m,flag[111][111][111],k,sx,sy,ex,ey;
char mp0[111][111],mp[111][111][111];
struct monster
{
	char tp;
	int x[111],y[111],k;
}mst[111];
struct node
{
	int x,y,v;
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
int check(int x,int y,int z)
{
	if(x<1||y<1||x>n||y>m||mp0[x][y]=='#'||mp[x][y][z%k]=='#') return 0;
	return 1;
}
int bfs()
{
	int i;
	node t,next;
	priority_queue<node> q;
	mem(flag,0);
	t.x=sx;
	t.y=sy;
	t.v=0;
	flag[t.x][t.y][t.v]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(mp[t.x][t.y][(t.v+1)%k]=='#') continue;
		if(t.v>100) continue;
		next=t;
		next.v++;
		if(check(next.x,next.y,next.v))
		{
			if(!flag[next.x][next.y][next.v]) q.push(next);
			flag[next.x][next.y][next.v]=1;
		}
		for(i=0;i<8;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			next.v=t.v+1;
			if(check(next.x,next.y,next.v))
			{
				if(next.x==ex&&next.y==ey) return next.v;
				if(!flag[next.x][next.y][next.v]) q.push(next);
				flag[next.x][next.y][next.v]=1;
				next.x+=dir[i][0];
				next.y+=dir[i][1];
				if(check(next.x,next.y,next.v))
				{
					if(next.x==ex&&next.y==ey) return next.v;
					if(!flag[next.x][next.y][next.v]) q.push(next);
					flag[next.x][next.y][next.v]=1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,j,l,q,tag=0;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		if(tag) puts("");
		tag=1;
		getchar();
		mem(mp0,0);
		for(i=1;i<=n;i++)
		{
			scanf("%s",mp0[i]+1);
			for(j=1;j<=m;j++)
			{
				if(mp0[i][j]=='p')
				{
					sx=i;
					sy=j;
					mp0[i][j]='.';
				}
				else if(mp0[i][j]=='t')
				{
					ex=i;
					ey=j;
					mp0[i][j]='.';
				}
			}
		}
		scanf("%d",&q);
		k=0;
		for(i=0;i<q;i++)
		{
			mem(mst[i].x,0);
			mem(mst[i].y,0);
			scanf("%d",&mst[i].k);
			k=max(k,mst[i].k);
			for(j=0;j<mst[i].k;j++)
			{
				scanf("%d%d",&mst[i].x[j],&mst[i].y[j]);
				if(!j)
				{
					mst[i].tp=mp0[mst[i].x[j]][mst[i].y[j]];
					mp0[mst[i].x[j]][mst[i].y[j]]='.';
				}
			}
		}
		if(k==0) k++; 
		for(l=0;l<k;l++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					mp[i][j][l]=mp0[i][j];
				}
			}
		}
		node t,next;
		for(i=0;i<q;i++)
		{
			for(j=0;j<k;j++)
			{
				t.x=mst[i].x[j%mst[i].k];
				t.y=mst[i].y[j%mst[i].k];
				mp[t.x][t.y][j]='#';
				if(mst[i].tp=='a')
				{
					for(l=0;l<8;l++)
					{
						next.x=t.x+dir[l][0];
						next.y=t.y+dir[l][1];
						mp[next.x][next.y][j]='#';
					}
				}
			}
		}
		int ans=bfs();
		if(ans==-1) puts("impossible");
		else printf("%d\n",ans);
	}
	return 0;
}
/*
3 3
p#n
..#
n#t
2
2 3 1 3 3
3 1 3 2 2 3 3
*/