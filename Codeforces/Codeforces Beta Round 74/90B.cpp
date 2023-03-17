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
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int flag[111][111],n,m;
char a[111][111];
void del(int x,int y)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(a[x][y]==a[x][i]&&i!=y)
		{
			flag[x][y]=flag[x][i]=1;
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[x][y]==a[i][y]&&i!=x)
		{
			flag[x][y]=flag[i][y]=1;
		}
	}
}
int main()
{
	int i,j;
	while(~scanf("%d%d",&n,&m))
	{
		mem(a,0);
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				scanf("%c",&a[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				del(i,j);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(!flag[i][j]) printf("%c",a[i][j]);
			}
		}
		puts("");
	}
    return 0;
}