////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-10 14:11:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
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
int n,m,b[11][11];
char a[11][11];
void dfs(int i,int j)
{
	if(i==n||j==m) return;
	if(b[i][j]==2) return;
	b[i][j]++;
	if(a[i][j]=='N') dfs(i-1,j);
	if(a[i][j]=='S') dfs(i+1,j);
	if(a[i][j]=='W') dfs(i,j-1);
	if(a[i][j]=='E') dfs(i,j+1);
}
int main()
{
	int i,j,y,s1,s2;
	while(cin>>n>>m&&(n+m))
	{
		cin>>y;
		mem(a,0);
		mem(b,0);
		s1=s2=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		}
		dfs(0,y-1);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(b[i][j]==1) s1++;
				if(b[i][j]==2) s2++;
			}
		}
		if(s2) printf("%d step(s) before a loop of %d step(s)\n",s1,s2);
		else printf("%d step(s) to exit\n",s1);
	}
    return 0;
}
