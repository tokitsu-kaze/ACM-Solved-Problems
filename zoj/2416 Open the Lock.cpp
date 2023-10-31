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
const int MAX=100000+10;
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
char s[6],e[6];
int flag[10010];
struct node
{
	int v;
	char n[6];
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int bfs()
{
	int i,temp;
	node t,next;
	priority_queue<node> q;
	temp=atoi(s);
	strcpy(t.n,s);
	t.v=0;
	flag[temp]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(strcmp(t.n,e)==0) return t.v;
		for(i=0;i<4;i++)
		{
			strcpy(next.n,t.n);
			if(next.n[i]=='9') next.n[i]='1';
			else next.n[i]++;
			temp=atoi(next.n);
			if(!flag[temp])
			{
				next.v=t.v+1;
				flag[temp]=1;
				q.push(next);
			}
		}
		for(i=0;i<4;i++)
		{
			strcpy(next.n,t.n);
			if(next.n[i]=='1') next.n[i]='9';
			else next.n[i]--;
			temp=atoi(next.n);
			if(!flag[temp])
			{
				next.v=t.v+1;
				flag[temp]=1;
				q.push(next);
			}
		}
		for(i=1;i<4;i++)
		{
			strcpy(next.n,t.n);
			swap(next.n[i-1],next.n[i]);
			temp=atoi(next.n);
			if(!flag[temp])
			{
				next.v=t.v+1;
				flag[temp]=1;
				q.push(next);
			}
		}
	}
}
int main()
{
	int t;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf(" %s %s",s,e);
			mem(flag,0);
			printf("%d\n",bfs());
		}
	}
	return 0;
}