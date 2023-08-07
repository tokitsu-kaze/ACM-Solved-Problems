////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-06 22:27:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3635
////Problem Title: 
////Run result: Accept
////Run time:499MS
////Run memory:1724KB
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
#define MAX 10000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int n;
struct tree
{
	int pre,cnt,sum;
}p[10010];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		p[i].pre=i;
		p[i].cnt=0;
		p[i].sum=1;
	}
}
int find(int x)
{
	int temp;
	if(p[x].pre!=x)
	{
		temp=p[x].pre;
		p[x].pre=find(p[x].pre);
		p[x].cnt+=p[temp].cnt;
	}
	return p[x].pre;
}
void merge(int a,int b)
{
	int ta,tb;
	ta=find(a);
	tb=find(b);
	if(ta!=tb)
	{
		p[ta].pre=tb;
		p[ta].cnt++;
		p[tb].sum+=p[ta].sum;
		p[ta].sum=0;
	}
}
int main()
{
    int t,cas,q,a,b,c,tc;
    char s;
    while(cin>>t)
    {
		cas=1;
		while(t--)
		{
			scanf("%d%d",&n,&q);
			init();
			printf("Case %d:\n",cas++);
			while(q--)
			{
				getchar();
				scanf("%c",&s);
				if(s=='T')
				{
					scanf("%d%d",&a,&b);
					merge(a,b);
				}
				else if(s=='Q')
				{
					scanf("%d",&c);
					tc=find(c);
					printf("%d %d %d\n",tc,p[tc].sum,p[c].cnt);
				}
			}
		}
	}
    return 0;
}