////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-18 13:24:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4907
////Problem Title: 
////Run result: Accept
////Run time:374MS
////Run memory:8708KB
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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=200000+10;
const ll mod=1e6;
int pre[MAX];
void init()
{
	for(int i=1;i<MAX;i++)
	{
		pre[i]=i;
	}
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
	if(ra>rb) pre[rb]=ra;
	else if(rb>ra) pre[ra]=rb;
}
int main()
{
	int t,n,m,a;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			init();
			scanf("%d%d",&n,&m);
			while(n--)
			{
				scanf("%d",&a);
				merge(a,a+1);
			}
			while(m--)
			{
				scanf("%d",&a);
				printf("%d\n",find(a));
			}
		}
	}
	return 0;
}
