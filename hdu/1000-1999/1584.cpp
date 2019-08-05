////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-12 15:01:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1584
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1564KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 200+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int a[11],flag[11],ans;
void dfs(int cnt,int sum)
{
	int i,j,temp1,temp2[11];
	if(cnt==10)
	{
		ans=min(ans,sum);
		return;
	}
	for(i=1;i<10;i++)
	{
		if(!flag[i])
		{
			if(sum+abs(a[i]-a[i+1])>ans) return;
			flag[i]=1;
			temp1=abs(a[i]-a[i+1]);
			temp2[i]=a[i];
			a[i]=a[i+1];
			for(j=1;j<=10;j++)
			{
				if(a[j]==temp2[i])
				{
					temp2[j]=a[j];
					a[j]=a[i+1];
				}
			}
			dfs(cnt+1,sum+temp1);
			flag[i]=0;
			for(j=1;j<=10;j++)
			{
				if(a[j]==a[i])
				{
					a[j]=temp2[j];
				}
			}
			a[i]=temp2[i];
		}
	}
}
int main()
{
	int t,i,j,temp;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			mem(a,0);
			mem(flag,0);
			for(i=1;i<=10;i++)
			{
				scanf("%d",&temp);
				a[temp]=i;
			}
			ans=INF;
			dfs(1,0);
			printf("%d\n",ans);
		}
	}
    return 0;
}