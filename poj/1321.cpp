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
int ans,n,k,flag[11];
char a[11][11];
void dfs(int row,int aim)
{
	int i;
	if(aim==k)
	{
		ans++;
		return;
	}
	if(row>n) return;
	for(i=1;i<=n;i++)
	{
		if(a[row][i]=='#'&&!flag[i])
		{
			flag[i]=1;
			dfs(row+1,aim+1);
			flag[i]=0;
		}
	}
	dfs(row+1,aim);
}
int main()
{
    int i,j;
	while(cin>>n>>k)
	{
		if(n==-1&&k==-1) break;
		mem(a,'.');
		mem(flag,0);
		getchar();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%c",&a[i][j]);
			}
			getchar();
		}
		ans=0;
		dfs(1,0);
		cout<<ans<<endl;
	} 
    return 0;
}