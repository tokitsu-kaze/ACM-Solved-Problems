////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-31 21:52:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1484
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1580KB
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
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=50000+10;
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
int sx,sy,ex,ey;
int mp[11][11][4];//0zuo 1shang 2you 3xia
int flag[11][11];
struct node
{
	int x,y,v,dir;
}pre[11][11];
int check(int x,int y)
{
	if(x<1||y<1||x>6||y>6||flag[x][y]) return 0;
	return 1;
}
void bfs()
{
	int i;
	node t,next;
	queue<node> q;
	t.x=sx;
	t.y=sy;
	t.v=0;
	t.dir=-1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.x==ex&&t.y==ey)
		{
	//		cout<<t.v<<"++++"<<endl;
			return;
		}
		next.x=t.x;
		next.y=t.y-1;
		if(check(next.x,next.y))//shang 
		{
			if(!mp[t.x][t.y][1])
			{
	//			cout<<next.x<<" "<<next.y<<"^^"<<endl;
				pre[next.x][next.y].x=t.x;
				pre[next.x][next.y].y=t.y;
				pre[next.x][next.y].dir=1;
				flag[next.x][next.y]=1;
				next.v=t.v+1;
				q.push(next);
			}
		}
		next.x=t.x;
		next.y=t.y+1;
		if(check(next.x,next.y))//xia 
		{
			if(!mp[t.x][t.y][3])
			{
				pre[next.x][next.y].x=t.x;
				pre[next.x][next.y].y=t.y;
				pre[next.x][next.y].dir=3;
				flag[next.x][next.y]=1;
				next.v=t.v+1;
				q.push(next);
			}
		}
		next.x=t.x-1;
		next.y=t.y;
		if(check(next.x,next.y))//zuo 
		{
			if(!mp[t.x][t.y][0])
			{
				pre[next.x][next.y].x=t.x;
				pre[next.x][next.y].y=t.y;
				pre[next.x][next.y].dir=0;
				flag[next.x][next.y]=1;
				next.v=t.v+1;
				q.push(next);
			}
		}
		next.x=t.x+1;
		next.y=t.y;
		if(check(next.x,next.y))//you
		{
			if(!mp[t.x][t.y][2])
			{
				pre[next.x][next.y].x=t.x;
				pre[next.x][next.y].y=t.y;
				pre[next.x][next.y].dir=2;
				flag[next.x][next.y]=1;
				next.v=t.v+1;
				q.push(next);
			}
		}
	}
}
int main()
{
	int x1,y1,x2,y2,i,j,cnt,ans[41][2],temp,k;
	char ans1[41];
    while(~scanf("%d%d",&sx,&sy)&&(sx+sy))
    {
		mem(mp,0);
		mem(flag,0);
		scanf("%d%d",&ex,&ey);
		for(i=0;i<3;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2)
			{
				if(x1==0)
				{
					temp=min(y1,y2);
					y2=y1+y2-temp;
					temp=y1;
					for(j=y1+1;j<=y2;j++)
					{
						if(x1+1<=6) mp[x1+1][j][0]=1;//zuo
		//				cout<<x1+1<<" "<<j<<"*"<<endl;
					}
				}
				else
				{
					temp=min(y1,y2);
					y2=y1+y2-temp;
					temp=y1;
					for(j=y1+1;j<=y2;j++)
					{
						if(x1+1<=6) mp[x1+1][j][0]=1;//zuo
						mp[x1][j][2]=1;//you
		//				cout<<x1+1<<" "<<j<<"*"<<endl;
		//				cout<<x1<<" "<<j<<"*"<<endl;
					}
				}
			}
			else if(y1==y2)
			{
				if(y1==0)
				{
					temp=min(x1,x2);
					x2=x1+x2-temp;
					temp=x1;
					for(j=x1+1;j<=x2;j++)
					{
						if(y1+1<=6) mp[j][y1+1][1]=1;//shang
		//				cout<<j<<" "<<y1+1<<"*"<<endl;
					}
				}
				else
				{
					temp=min(x1,x2);
					x2=x1+x2-temp;
					temp=x1;
					for(j=x1+1;j<=x2;j++)
					{
						if(y1+1<=6) mp[j][y1+1][1]=1;//shang
						mp[j][y1][3]=1;//xia
		/*				cout<<j<<" "<<y1+1<<"*"<<endl;
						cout<<j<<" "<<y1<<"*"<<endl;*/
					}
				}
			}
		}
		bfs();
		mem(ans,0);
		mem(ans1,0);
		cnt=k=0;
		ans[cnt][0]=ex;
		ans[cnt][1]=ey;
		cnt++;
		for(i=ex,j=ey;;)
		{
			if(pre[i][j].x!=sx||pre[i][j].y!=sy)
			{
	//			cout<<pre[i][j].x<<" "<<pre[i][j].y<<"!!!"<<endl;
				ans[cnt][0]=pre[i][j].x;
				ans[cnt][1]=pre[i][j].y;
	//			ans1[k++]=pre[i][j].dir;
				cnt++;
				temp=i;
				i=pre[i][j].x;
				j=pre[temp][j].y;
			}
			else
			{
				ans[cnt][0]=sx;
				ans[cnt][1]=sy;
	//			ans1[k++]=pre[sx][sy].dir;
				break;
			}
		}
		for(i=cnt;i>=1;i--)
		{
	//		printf("(%d, %d)\n",ans[i][0],ans[i][1]);
			if(ans[i][0]+1==ans[i-1][0]) ans1[k++]='E';
			else if(ans[i][0]-1==ans[i-1][0]) ans1[k++]='W';
			else if(ans[i][1]+1==ans[i-1][1]) ans1[k++]='S';
			else if(ans[i][1]-1==ans[i-1][1]) ans1[k++]='N';
		}
	//	cout<<k<<endl;
		for(i=0;i<k;i++)
		{
			printf("%c",ans1[i]);
		}
		puts("");
	}
    return 0;
}
/*
1 1
6 1
1 0 1 5
1 5 5 5
5 5 5 0
0 0
*/