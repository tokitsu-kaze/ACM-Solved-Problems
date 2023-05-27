////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 11:17:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1495
////Problem Title: 
////Run result: Accept
////Run time:514MS
////Run memory:7100KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int cup[5];
int flag[111][111][111];
struct node
{
	int cup[5],v;
};
void pour(int a,int b,node *t)
{
	int temp;
	temp=t->cup[a]+t->cup[b];
	if(temp>=cup[b])
	{
		t->cup[b]=cup[b];
		t->cup[a]=temp-cup[b];
	}
	else
	{
		t->cup[b]=temp;
		t->cup[a]=0;
	}
}
void bfs()
{
	int i,j;
	node t,next;
	queue<node> q;
	mem(flag,0);
	t.cup[1]=cup[1];
	t.cup[2]=0;
	t.cup[3]=0;
	flag[cup[1]][0][0]=1;
	t.v=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
//		cout<<t.cup[1]<<" "<<t.cup[2]<<" "<<t.cup[3]<<endl;
		if((t.cup[1]==t.cup[2]&&t.cup[3]==0&&t.cup[1])||(t.cup[2]==t.cup[3]&&t.cup[1]==0&&t.cup[2])||(t.cup[3]==t.cup[1]&&t.cup[2]==0&&t.cup[3]))
		{
			printf("%d\n",t.v);
			return;
		}
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				if(i!=j)
				{
					next=t;
					pour(i,j,&next);
					if(!flag[next.cup[1]][next.cup[2]][next.cup[3]])
					{
						flag[next.cup[1]][next.cup[2]][next.cup[3]]=1;
						next.v++;
						q.push(next);
					}
				}
			}
		}
	}
	puts("NO");
} 
int main()
{
	while(~scanf("%d%d%d",&cup[1],&cup[2],&cup[3])&&(cup[1]+cup[2]+cup[3]))
	{
		bfs();
	}
	return 0;
}
