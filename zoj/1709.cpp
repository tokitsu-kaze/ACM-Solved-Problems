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
int m,n,flag[110][110];
char a[110][110];
void dfs(int i,int j)
{
	if(i+1<m&&a[i+1][j]=='@'&&!flag[i+1][j])
	{
		flag[i+1][j]=1;
		dfs(i+1,j);
	}
	if(i-1>=0&&a[i-1][j]=='@'&&!flag[i-1][j])
	{
		flag[i-1][j]=1;
		dfs(i-1,j);
	}
	if(j+1<n&&a[i][j+1]=='@'&&!flag[i][j+1])
	{
		flag[i][j+1]=1;
		dfs(i,j+1);
	}
	if(j-1>=0&&a[i][j-1]=='@'&&!flag[i][j-1])
	{
		flag[i][j-1]=1;
		dfs(i,j-1);
	}
	if(i+1<m&&j+1<n&&a[i+1][j+1]=='@'&&!flag[i+1][j+1])
	{
		flag[i+1][j+1]=1;
		dfs(i+1,j+1);
	}
	if(i-1>=0&&j+1<n&&a[i-1][j+1]=='@'&&!flag[i-1][j+1])
	{
		flag[i-1][j+1]=1;
		dfs(i-1,j+1);
	}
	if(i+1<m&&j-1>=0&&a[i+1][j-1]=='@'&&!flag[i+1][j-1])
	{
		flag[i+1][j-1]=1;
		dfs(i+1,j-1);
	}
	if(i-1>=0&&j-1>=0&&a[i-1][j-1]=='@'&&!flag[i-1][j-1])
	{
		flag[i-1][j-1]=1;
		dfs(i-1,j-1);
	}
	return;
}
int main()
{
	int i,j,ans;
	while(cin>>m>>n&&(m+n))
	{
		mem(a,0);
		mem(flag,0);
		ans=0;
		for(i=0;i<m;i++)
		{
			scanf("%s",a[i]);
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]=='@'&&!flag[i][j])
				{
					dfs(i,j);
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}