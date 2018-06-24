////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-09 23:32:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:1596KB
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
#define MAX 10000+10
using namespace std;
typedef long long ll;
int k,flag[11][11],flag2,x,y,sx,sy,n,m;
char a[11][11];
void dfs(int i,int j,int aim)
{
	if(aim==k)
	{
		if(a[i][j]=='D')
		{
			puts("YES");
			flag2=0;
		}
		return;
	}
	if((k-aim)%2!=(abs(x-i)+abs(y-j))%2) return;
	if(k-aim<abs(x-i)+abs(y-j)) return;
	if(i+1<n&&!flag[i+1][j])
	{
		flag[i+1][j]=1;
		dfs(i+1,j,aim+1);
		flag[i+1][j]=0;
		if(!flag2) return;
	}
	if(j+1<m&&!flag[i][j+1])
	{
		flag[i][j+1]=1;
		dfs(i,j+1,aim+1);
		flag[i][j+1]=0;
		if(!flag2) return;
	}
	if(i-1>=0&&!flag[i-1][j])
	{
		flag[i-1][j]=1;
		dfs(i-1,j,aim+1);
		flag[i-1][j]=0;
		if(!flag2) return;
	}
	if(j-1>=0&&!flag[i][j-1])
	{
		flag[i][j-1]=1;
		dfs(i,j-1,aim+1);
		flag[i][j-1]=0;
		if(!flag2) return;
	}
	return;
}
int main()
{
    int i,j;
	while(cin>>n>>m>>k&&(n+m+k))
	{
		mem(a,0);
		mem(flag,0);
		flag2=1;
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				if(a[i][j]=='D')
				{
					x=i;
					y=j;
				}
				if(a[i][j]=='X') flag[i][j]=1;
			}
		}
		flag[sx][sy]=1;
		dfs(sx,sy,0);
		if(flag2) puts("NO");
	}
    return 0;
}
