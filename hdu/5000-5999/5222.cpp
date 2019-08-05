////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-15 22:28:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5222
////Problem Title: 
////Run result: Accept
////Run time:5038MS
////Run memory:31924KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 1000000+10
#define EDGE 1000000+10//±ßµÄÌõÊý 
#pragma comment(linker, "/STACK:102400000,102400000") 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int in_degree[MAX];
int head[MAX];
int pre[MAX];
int n,flag,num,cnt;
struct node
{
	int next,to,w;
}mp[EDGE];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		pre[i]=i;
	}
}
void add(int a,int b)
{
	mp[num].to=b;
	mp[num].next=head[a];
	head[a]=num++;
	in_degree[b]++;
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(int a,int b)
{
	int ra,rb;
	ra=find(a);
	rb=find(b);
	if(ra!=rb) pre[ra]=rb;
	else if(ra==rb) flag=1;
}
void topsort()
{
	int i,t,to;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in_degree[i]) q.push(i);
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		cnt++;
		for(i=head[t];i!=-1;i=mp[i].next)
		{
			to=mp[i].to;
			in_degree[to]--;
			if(!in_degree[to])
			{
				q.push(to);
			}
		}
	}
}
int main()
{
	int t,m1,m2,a,b,i;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d",&n,&m1,&m2);
			fill(head,head+n,-1);
			mem(in_degree,0);
			init();
			flag=0;
			num=0;
			for(i=0;i<m1;i++)
			{
				scanf("%d%d",&a,&b);
				if(flag) continue;
				merge(a,b);
			}
			for(i=0;i<m2;i++)
			{
				scanf("%d%d",&a,&b);
				a=find(a);
				b=find(b);
				if(a==b) flag=1;
				if(flag) continue; 
				add(a,b);
			}
			if(flag)
			{
				puts("YES");
				continue;
			}
			cnt=0;
			topsort();
			if(cnt<n) puts("YES");
			else puts("NO");
		}
	}
    return 0;
}