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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=5e3+10;
const ll mod=1e9+7;
char mp[111][111];
int n,m,flag[111][111],dir[4][2]={0,1,1,0,0,-1,-1,0},ex,ey;
struct node
{
	int x,y;
	node(){}
	node(int a,int b)
	{
		x=a;
		y=b;
	}
}pre[111][111];
bool check(int x,int y)
{
	if(x<1||y<1||x>n||y>m||flag[x][y]||mp[x][y]=='*') return 0;
	return 1;
}
void bfs()
{
	node t,next;
	int i;
	queue<node> q;
	t.x=1;
	t.y=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			next=t;
			next.x+=dir[i][0];
			next.y+=dir[i][1];
			if(check(next.x,next.y))
			{
				flag[next.x][next.y]=1;
				pre[next.x][next.y]=t;
				if(mp[next.x][next.y]=='F')
				{
					ex=next.x;
					ey=next.y;
					return;
				}
				q.push(next);
			}
		}
	}
}
map<pair<int,int>,char> op;
int main()
{
	int i,j,x,y;
	while(~scanf("%d%d",&n,&m))
	{
		mem(pre,0);
		for(i=1;i<=n;i++)
		{
			scanf("%s",mp[i]+1);
		}
		bfs();
		x=ex;
		y=ey;
		stack<node> s;
		s.push(node(x,y));
		while(!(x==1&&y==1))
		{
			s.push(pre[x][y]);
			int temp=x;
			x=pre[x][y].x;
			y=pre[temp][y].y;
	//		cout<<x<<" "<<y<<endl;
		}
		op[MP(1,0)]='D';
		op[MP(-1,0)]='U';
		op[MP(0,1)]='R';
		op[MP(0,-1)]='L';
		node t,next;
		t=s.top();
		s.pop();
		while(!s.empty())
		{
			next=s.top();
			s.pop();
			printf("%c\n",op[MP(next.x-t.x,next.y-t.y)]);
			fflush(stdout);
			scanf("%d%d",&x,&y);
			if(x!=next.x||y!=next.y)
			{
				if(op[MP(next.x-t.x,next.y-t.y)]=='R')
				{
					op[MP(next.x-t.x,next.y-t.y)]='L';
					op[MP(t.x-next.x,t.y-next.y)]='R';
				}
				else if(op[MP(next.x-t.x,next.y-t.y)]=='L')
				{
					op[MP(next.x-t.x,next.y-t.y)]='R';
					op[MP(t.x-next.x,t.y-next.y)]='L';
				}
				else if(op[MP(next.x-t.x,next.y-t.y)]=='U')
				{
					op[MP(next.x-t.x,next.y-t.y)]='D';
					op[MP(t.x-next.x,t.y-next.y)]='U';
				}
				else if(op[MP(next.x-t.x,next.y-t.y)]=='D')
				{
					op[MP(next.x-t.x,next.y-t.y)]='U';
					op[MP(t.x-next.x,t.y-next.y)]='D';
				}
				printf("%c\n",op[MP(next.x-t.x,next.y-t.y)]);
				fflush(stdout);
				scanf("%d%d",&x,&y);
			}
			t=next;
		}
	}
	return 0;
}