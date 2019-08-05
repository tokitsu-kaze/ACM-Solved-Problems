////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-05 12:49:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1998
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1560KB
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
int n,ans[21][21];
void dfs(int x,int y,int a)
{
	ans[x][y]=a;
	if(a==n*n) return;
	if((x-1<0&&y+1>=n)) dfs(x+1,y,a+1);
	else if(x-1<0) dfs(n-1,y+1,a+1);
	else if(y+1>=n) dfs(x-1,0,a+1);
	else if(ans[x-1][y+1]) dfs(x+1,y,a+1);
	else dfs(x-1,y+1,a+1);

}
int main()
{
	int t,i,j;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			mem(ans,0);
			dfs(0,n/2,1);
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					printf("%4d",ans[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}