////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-10 11:16:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6026
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
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
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct node
{
	ll n,v;
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
ll dis[55],flag[55],n;
ll mp[55][55];
void dijkstra(ll s)
{
	priority_queue<node> q;
	node t,next;
	ll i;
	mem(dis,0x3f);
	mem(flag,0);
	dis[s]=0;
	t.n=s;
	t.v=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.n]) continue;
		flag[t.n]=1;
		for(i=0;i<n;i++)
		{
			if(mp[t.n][i]!=INF&&dis[i]>dis[t.n]+mp[t.n][i])
			{
				dis[i]=dis[t.n]+mp[t.n][i];
				next.n=i;
				next.v=dis[i];
				q.push(next);
			}
		}
	}
}
int main()
{
	ll i,j,ans,cnt[55];
	char t[55][55];
	while(~scanf("%I64d",&n))
	{
		mem(mp,0);
		mem(t,0);
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",t[i]);
			for(j=0;j<n;j++)
			{
				mp[i][j]=t[i][j]-'0';
				if(mp[i][j]==0) mp[i][j]=INF;
			}
		}
		dijkstra(0);
		mem(cnt,0);
		for(i=1;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(mp[i][j]!=INF&&dis[j]+mp[i][j]==dis[i]) cnt[i]++;
			}
		}
		ans=1;
		for(i=0;i<n;i++)
		{
			if(cnt[i]) ans=ans*cnt[i]%mod;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}