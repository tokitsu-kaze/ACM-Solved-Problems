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
const int MAX=1e3+10;
const ll mod=1e6;
int n,cnt,top,k;
vector<int> mp[MAX];
int low[MAX],dfn[MAX],belong[MAX],cnt2[MAX];
int sstack[MAX],flag[MAX];
int begin[MAX];
int tag;
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
	}
	mem(low,0);
	mem(dfn,0);
	mem(sstack,0);
	mem(flag,0);
	cnt=top=k=0;
	mem(cnt2,0);
	mem(begin,0);
}
void tarjan(int now)
{
	int to,i,temp;
	sstack[top++]=now;
	flag[now]=1;//±ê¼Ç½øÕ»
	low[now]=dfn[now]=++k;
	for(i=0;i<mp[now].size();i++)
	{
		to=mp[now][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if(flag[to]) low[now]=min(low[now],dfn[to]);
	}
	if(low[now]==dfn[now])
	{
		cnt++;
		do
		{
			temp=sstack[--top];
			flag[temp]=0;
			belong[temp]=cnt;
			cnt2[cnt]++;
			begin[cnt]=temp;
		}while(temp!=now);
	}
}
void dfs(int x,int k)
{
	if(tag) return;
	if(belong[x]!=k)
	{
		tag=1;
		return;
	}
	flag[x]=1;
	int i;
	for(i=0;i<mp[x].size();i++)
	{
		if(!flag[mp[x][i]]) dfs(mp[x][i],k);
	}
}
int main()
{
	int a,b,m,i;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
		}
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
		int ans=0;
		for(i=1;i<=cnt;i++)
		{
	//		cout<<cnt2[i]<<endl;
			if(cnt2[i]>2)
			{
				tag=0;
				mem(flag,0);
				dfs(begin[i],i);
				if(!tag) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 