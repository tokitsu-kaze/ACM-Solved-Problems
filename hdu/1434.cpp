////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-05 14:17:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1434
////Problem Title: 
////Run result: Accept
////Run time:951MS
////Run memory:21652KB
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
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
struct train
{
	char name[21];
	int rp;
	friend bool operator<(train a,train b)
	{
		if(a.rp==b.rp) return strcmp(a.name,b.name)<0;
		return a.rp>b.rp;
	}
}t;
int main()
{
    int n,m,i,x,len,a,b;
    char op[11];
    while(cin>>n>>m)
    {
		priority_queue<train> q[10010];
		for(i=1;i<=n;i++)
		{
			cin>>x;
			while(x--)
			{
				scanf("%s%d",t.name,&t.rp);
				q[i].push(t);
			}
		}
		while(m--)
		{
			scanf("%s",op);
			len=strlen(op);
			if(len==5)
			{
				scanf("%d %s %d",&a,t.name,&t.rp);
				q[a].push(t);
			}
			else if(len==4)
			{
				cin>>a>>b;
				while(!q[b].empty())
				{
					t=q[b].top();
					q[b].pop();
					q[a].push(t);
				}
			}
			else if(len==6)
			{
				cin>>a;
				cout<<q[a].top().name<<endl;
				q[a].pop();
			}
		}
	}
    return 0;
}
