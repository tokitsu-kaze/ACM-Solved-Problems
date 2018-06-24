////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-11 12:04:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2112
////Problem Title: 
////Run result: Accept
////Run time:1653MS
////Run memory:5648KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 1000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int n,k;
int mp[MAX][MAX];
int dis[MAX];
int flag[MAX];
struct node
{
	int n,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
void dijkstra()
{
	int i;
	node t,next;
	priority_queue<node> q;
	t.n=1;
	t.v=0;
	dis[1]=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.n]) continue;
		flag[t.n]=1;
		for(i=1;i<k;i++)
		{
			if(mp[t.n][i]!=INF&&dis[i]>dis[t.n]+mp[t.n][i])
			{
				dis[i]=dis[t.n]+mp[t.n][i];
				next.n=i;
				next.v=dis[i];
				q.push(next);
			}
		}
	}
}
int main()
{
	int i,j,c,flag2;
	char a[41],b[41];
	map<string,int> m;
    while(~scanf("%d",&n)&&n!=-1)
    {
		m.clear();
		mem(mp,0x3f);
		mem(dis,0x3f);
		mem(flag,0);
		getchar();
		flag2=0;
		scanf("%s %s",a,b);
		if(strcmp(a,b)==0) flag2=1;
		k=1;
		m[a]=k++;
		m[b]=k++;
	//	printf("%d %d\n",m[a],m[b]);
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%s %s %d",a,b,&c);
			if(!m[a]) m[a]=k++;
			if(!m[b]) m[b]=k++;
	//		printf("%d %d\n",m[a],m[b]);
			if(mp[m[a]][m[b]]>c) mp[m[a]][m[b]]=mp[m[b]][m[a]]=c;
		}
	//	cout<<k<<endl;
		if(flag2)
		{
			puts("0");
			continue;
		}
		dijkstra();
		if(dis[2]!=INF) printf("%d\n",dis[2]);
		else puts("-1");
	}
    return 0;
}