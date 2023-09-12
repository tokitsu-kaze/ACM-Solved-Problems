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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2200+10;
const ll mod=1e9+6;
int mp[111][111],ans,n;
int tag[111];
void dfs(int p,int s)
{
	int i,flag=0;
	
	for(i=0;i<n;i++)
	{
		if(mp[p][i]&&!tag[i])
		{
			flag=1;
			tag[i]=1;
			dfs(i,s+mp[p][i]);
			tag[i]=0;
		}
	}
	if(!flag) ans=max(ans,s);
}
int main()
{
	int a,b,c,i;
	while(~scanf("%d",&n))
	{
		mem(mp,0);
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[a][b]=mp[b][a]=c;
		}
		ans=-1;
		mem(tag,0);
		tag[0]=1;
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}