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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e6;
vector<int> mp[MAX];
int tag[MAX],flag;
void dfs(int x,int now)
{
	int i,sz;
	if(flag) return;
	if(tag[x])
	{
		if(tag[x]!=now) flag=1;
		return;
	}
	tag[x]=now;
	sz=mp[x].size();
	for(i=0;i<sz;i++)
	{
		dfs(mp[x][i],now==1?2:1);
	}
}
int main()
{
	int n,m,a,b,pos,cnt1,cnt2,ans1[MAX],ans2[MAX],i;
	while(~scanf("%d%d",&n,&m))
	{
		pos=0;
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			ans1[i]=0;
			ans2[i]=0;
			tag[i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		cnt1=cnt2=0;
		flag=0;
		for(i=1;i<=n;i++)
		{
			if(!tag[i]) dfs(i,1);
			if(flag) break;
		}
		if(!flag)
		{
			for(i=1;i<=n;i++)
			{
				if(tag[i]==1) ans1[cnt1++]=i;
				else if(tag[i]==2) ans2[cnt2++]=i;
			}
			printf("%d\n",cnt1);
			for(i=0;i<cnt1;i++)
			{
				if(i==cnt1-1) printf("%d\n",ans1[i]);
				else printf("%d ",ans1[i]);
			}
			printf("%d\n",cnt2);
			for(i=0;i<cnt2;i++)
			{
				if(i==cnt2-1) printf("%d\n",ans2[i]);
				else printf("%d ",ans2[i]);
			}
		}
		else puts("-1");
	}
	return 0;
}