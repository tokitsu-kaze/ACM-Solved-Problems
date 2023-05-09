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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int n,ex,ey,dir[8][2]={1,2,-1,2,1,-2,-1,-2,-2,1,2,1,-2,-1,2,-1};
int flag[311][311];
struct node
{
	int x,y,v;
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=n||flag[x][y]) return 0;
	return 1;
}
int bfs(int x,int y)
{
	int i;
	node t,next;
	queue<node> q;
	mem(flag,0);
	t.x=x;
	t.y=y;
	t.v=0;
	flag[x][y]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.x==ex&&t.y==ey) return t.v;
		for(i=0;i<8;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				flag[next.x][next.y]=1;
				next.v=t.v+1;
				q.push(next);
			}
		}
	}
}
int main()
{
	int t,sx,sy;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			cin>>sx>>sy;
			cin>>ex>>ey;
			cout<<bfs(sx,sy)<<endl;
		}
	}
	return 0;
}