////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-05 12:56:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1509
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1604KB
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
struct message
{
	char name[21];
	int par,pri,id;
	friend bool operator<(message a,message b)
	{
		if(a.pri==b.pri) return a.id>b.id;
		return a.pri>b.pri;
	}
}m;
int main()
{
    int n,i,d,k;
    char a[5];
    priority_queue<message> q;
    k=1;
    while(~scanf("%s",a))
    {
		if(a[0]=='P')
		{
			scanf("%s %d %d",m.name,&m.par,&m.pri);
			m.id=k++;
			q.push(m);
		}
		else
		{
			if(q.empty()) puts("EMPTY QUEUE!");
			else
			{
				printf("%s %d\n",q.top().name,q.top().par);
				q.pop();
			}
		}
	}
    return 0;
}
