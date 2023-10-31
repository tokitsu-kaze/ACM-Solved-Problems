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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int mp[111][111],flag[111],ans[111],tag,n;
void dfs(int v,int cnt)
{
	if(cnt==n)
	{
		tag=1;
		for(int i=0;i<cnt;i++)
		{
			if(!i) printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		}
		puts("");
		return;
	}
	for(int i=1;i<=n&&!tag;i++)
	{
		if(mp[v][i]&&!flag[i])
		{
			flag[i]=1;
			ans[cnt]=i;
			dfs(i,cnt+1);
			flag[i]=0;
		}
	}
}
int main()
{
	int t,a,b,i,m;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			m=n*(n-1)/2;
			mem(mp,0);
			for(i=0;i<m;i++)
			{
				scanf("%d%d",&a,&b);
				mp[a][b]=1;
			}
			mem(flag,0);
			tag=0;
			for(i=1;i<=n;i++)
			{
				if(!tag)
				{
					mem(ans,0);
					ans[0]=i;
					flag[i]=1;
					dfs(i,1);
					flag[i]=0;
				}
			}
		}
	}
	return 0;
}