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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
char mp[55][55];
int flag[55][55][55];
int n;
struct node
{
	int a,b,c,v;
};
void bfs(int a,int b,int c)
{
	int i;
	node t,next;
	queue<node> q;
	t.a=a;
	t.b=b;
	t.c=c;
	t.v=0;
	flag[a][b][c]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.a==t.b&&t.b==t.c)
		{
			printf("%d\n",t.v);
			return;
		}
		for(i=1;i<=n;i++)
		{
			next=t;
			if(mp[t.a][i]==mp[t.b][t.c]&&mp[t.a][i]&&!flag[i][t.b][t.c])
			{
				next.v++;
				next.a=i;
				flag[next.a][next.b][next.c]=1;
				q.push(next);
			}
		}
		for(i=1;i<=n;i++)
		{
			next=t;
			if(mp[t.b][i]==mp[t.a][t.c]&&mp[t.b][i]&&!flag[t.a][i][t.c])
			{
				next.v++;
				next.b=i;
				flag[next.a][next.b][next.c]=1;
				q.push(next);
			}
		}
		for(i=1;i<=n;i++)
		{
			next=t;
			if(mp[t.c][i]==mp[t.a][t.b]&&mp[t.c][i]&&!flag[t.a][t.b][i])
			{
				next.v++;
				next.c=i;
				flag[next.a][next.b][next.c]=1;
				q.push(next);
			}
		}
	}
	puts("impossible");
}
int main()
{
	int a,b,c,i,j;
	char t[5];
	while(~scanf("%d",&n)&&n)
	{
		scanf("%d%d%d",&a,&b,&c);
		mem(mp,0);
		mem(flag,0); 
		getchar();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%s",t);
				mp[i][j]=t[0];
			}
		}
		bfs(a,b,c);
	}
	return 0;
}