////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-03 09:58:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2120
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1572KB
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
const int MAX=100000+10;
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
int pre[1111],ans;
void init(int n)
{
	int i;
	for(i=0;i<n;i++)
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
	if(ra!=rb) pre[ra]=rb;
	else ans++;
}
int main()
{
	int n,m,a,b,i;
	while(~scanf("%d%d",&n,&m))
	{
		init(n);
		ans=0;
		while(m--)
		{
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		printf("%d\n",ans);
	}
	return 0;
}