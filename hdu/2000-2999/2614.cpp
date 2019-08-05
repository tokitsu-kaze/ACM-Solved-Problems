////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 13:05:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2614
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1708KB
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
int n,mp[17][17],ans;
int flag[17];
void dfs(int num,int cnt,int temp)
{
	int i;
	for(i=1;i<n;i++)
	{
		if(!flag[i]&&mp[num][i]>=temp)
		{
			flag[i]=1;
			dfs(i,cnt+1,mp[num][i]);
			flag[i]=0;
		}
	}
	ans=max(ans,cnt);
}
int main()
{
	int i,j;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		mp[0][0]=0;
		mem(flag,0);
		ans=1;
		dfs(0,1,0);
		printf("%d\n",ans);
	}
	return 0;
}
