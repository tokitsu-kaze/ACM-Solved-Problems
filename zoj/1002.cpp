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
int n,flag[11][11],ans;
char a[11][11];
int check(int x,int y)
{
	int i,j;
	for(i=x;i>=0;i--)
	{
		if(a[i][y]=='X') break;
		if(flag[i][y]) return 0;
	}
	for(i=x;i<n;i++)
	{
		if(a[i][y]=='X') break;
		if(flag[i][y]) return 0;
	}
	for(i=y;i>=0;i--)
	{
		if(a[x][i]=='X') break;
		if(flag[x][i]) return 0;
	}
	for(i=y;i<n;i++)
	{
		if(a[x][i]=='X') break;
		if(flag[x][i]) return 0;
	}
	return 1;
}
void dfs(int cnt)
{
	int i,j;
	if(cnt>ans) ans=cnt;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]=='.'&&!flag[i][j]&&check(i,j))
			{
				flag[i][j]=1;
				dfs(cnt+1);
				flag[i][j]=0;
			}
		}
	}
}
int main()
{
	int i,j;
	while(cin>>n&&n)
	{
		mem(a,0);
		mem(flag,0);
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		}
		dfs(0);
		cout<<ans<<endl;
	}
    return 0;
}