////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-18 19:59:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1044
////Problem Title: 
////Run result: Accept
////Run time:967MS
////Run memory:15136KB
//////////////////System Comment End//////////////////
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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=40000+10;
const ll mod=1e6;
int n,m,limt,sx,sy,ex,ey,maxx;
char mp[55][55];
int flag[55][55][(1<<10)+10];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int val[13];
struct node
{
	int x,y,v,s,tag;
};
void bfs()
{
	int ans=-1,i;
	node t,next;
	queue<node> q;
	mem(flag,0);
	t.x=sx;
	t.y=sy;
	t.v=0;
	t.s=0;
	t.tag=0;
	q.push(t);
	flag[t.x][t.y][0]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.x==ex&&t.y==ey)
		{
			ans=max(ans,t.s);
			if(ans==maxx) break;
			continue;
		}
		if(t.v>limt) break;
		int dis=abs(t.x-ex)+abs(t.y-ey);
		if(t.v+dis>limt) continue;
		for(i=0;i<4;i++)
		{
			next=t;
			next.x+=dir[i][0];
			next.y+=dir[i][1];
			next.v++;
			if(mp[next.x][next.y]>='A'&&mp[next.x][next.y]<='Z')
			{
				int temp=1<<(mp[next.x][next.y]-'A');
				if(!(next.tag&temp))
				{
					next.s+=val[mp[next.x][next.y]-'A'];
					next.tag|=temp;
				}
			}
			if(next.x>=0&&next.y>=0&&next.x<n&&next.y<m&&mp[next.x][next.y]!='*'&&!flag[next.x][next.y][next.tag])
			{
				
				flag[next.x][next.y][next.tag]=1;
				q.push(next);
			}
		}
	}
	if(ans==-1) puts("Impossible");
	else printf("The best score is %d.\n",ans);
}
int main()
{
	int t,cas,i,j,k,a,tg;
	scanf("%d",&t);
	cas=1;
	while(t--)
	{
		scanf("%d%d%d%d",&m,&n,&limt,&k);
		mem(mp,0);
		mem(val,0);
		maxx=0;
		for(i=0;i<k;i++)
		{
			scanf("%d",&val[i]);
			maxx+=val[i];
		}
		getchar();
		tg=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m&&tg!=2;j++)
			{
				if(mp[i][j]=='@')
				{
					sx=i;
					sy=j;
					tg++;
				}
				else if(mp[i][j]=='<')
				{
					ex=i;
					ey=j;
					tg++;
				}
			}
		}
		printf("Case %d:\n",cas++);
		bfs();
		if(t) puts("");
	}
	return 0;
}
