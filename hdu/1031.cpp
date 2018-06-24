////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-05 16:38:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1031
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:11284KB
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
struct node
{
	int id;
	double sum;
}a[1010];
bool cmp1(node a,node b)
{
	return a.sum>b.sum;
}
bool cmp2(node a,node b)
{
	return a.id>b.id;
}
double mp[1111][1111];
int main()
{
	int i,j,n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		mem(mp,0);
		for(i=1;i<=m;i++)
		{
			a[i].id=i;
			a[i].sum=0;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lf",&mp[i][j]);
				a[j].sum+=mp[i][j];
			}
		}
		sort(a+1,a+m+1,cmp1);
		sort(a+1,a+k+1,cmp2);
		for(i=1;i<=k;i++)
		{
			if(i==1) printf("%d",a[i].id);
			else printf(" %d",a[i].id);
		}
		puts("");
	}
	return 0;
}