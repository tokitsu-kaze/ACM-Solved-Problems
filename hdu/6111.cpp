////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-16 23:15:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6111
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2836KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
struct node
{
	int x,y,t,key;
	ll rev;
	node(){}
	node(int a,int b,int c,int d,ull e)
	{
		x=a;
		y=b;
		t=c;
		key=d;
		rev=e;
	}
};
int n,m;
char mp[66][66];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
vector<ull> flag[66][66][2];
bool checkxy(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
bool check(int x,int y,int k,ull z)
{
	int i;
	for(i=0;i<sz(flag[x][y][k]);i++)
	{
		if(flag[x][y][k][i]==z) return 1;
	}
	return 0;
}
int bfs(int sx,int sy)
{
	int i,j,x,y;
	ull temp;
	node t,next;
	queue<node> q;
	q.push(node(sx,sy,0,0,0));
	flag[sx][sy][0].pb(0);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
	//	cout<<t.x+1<<" "<<t.y+1<<endl;
		for(i=0;i<4;i++)
		{
			next=t;
			next.x+=dir[i][0];
			next.y+=dir[i][1];
			if(checkxy(next.x,next.y))
			{
				temp=next.x*m+next.y;
				if(next.rev&(1ULL<<temp))
				{
					if(mp[next.x][next.y]!='x') continue;
				}
				else
				{
					if(mp[next.x][next.y]=='x') continue;
				}
				if(mp[next.x][next.y]=='E'&&next.key) return next.t+1;
				else if(mp[next.x][next.y]=='K') next.key=1;
				else if(mp[next.x][next.y]=='*')
				{
					for(j=0;j<4;j++)
					{
						x=next.x+dir[j][0];
						y=next.y+dir[j][1];
						if(checkxy(x,y))
						{
							temp=x*m+y;
							if(next.rev&(1ULL<<temp)) next.rev-=(1ULL<<temp);
							else next.rev+=(1ULL<<temp);
						}
					}
				}
				if(check(next.x,next.y,next.key,next.rev)) continue;
				next.t++;
				flag[next.x][next.y][next.key].pb(next.rev);
				q.push(next);
			}
		}
	}
	return -1;
}
int main()
{
	int t,i,j,k,sx,sy,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				flag[i][j][0].clear();
				flag[i][j][1].clear();
			}
		}
		printf("Case #%d:\n%d\n",cas++,bfs(sx,sy));
	}
	return 0;
}
