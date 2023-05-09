////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-26 09:41:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1372
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1612KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll; 
int flag[11][11],dir[8][2]={-1,2,-2,1,1,-2,2,-1,-1,-2,-2,-1,1,2,2,1};
char s[5],e[5];
struct map1
{
	int x,y;
	int s;
};
int check(int x,int y)
{
	if(x>=8||x<0||y>=8||y<0||flag[x][y]) return 0;
	return 1;
}
int bfs()
{
	mem(flag,0);
	int i;
	map1 t,next;
	queue<map1> q;
	t.x=s[0]-'a';
	t.y=s[1]-'1';
	t.s=0;
	q.push(t);
	flag[t.x][t.y]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.x==e[0]-'a'&&t.y==e[1]-'1') return t.s;
		for(i=0;i<8;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			next.s=t.s+1;
			if(check(next.x,next.y))
			{
				q.push(next);
				flag[next.x][next.y]=1;
			}
		}
	}
}
int main()
{ 
	int t,n,i;
	while(~scanf("%s%s",s,e))
	{
	//	cout<<s<<' '<<e<<endl;
		printf("To get from %s to %s takes %d knight moves.\n",s,e,bfs());
	}
    return 0;
}