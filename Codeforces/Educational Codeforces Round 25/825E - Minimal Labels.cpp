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
int indegree[MAX];
vector<int> mp[MAX];
int ans[MAX],cnt;
void topsort(int n)
{
	int i,t;
	priority_queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!indegree[i]) q.push(i);
	}
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		ans[t]=cnt--;
		for(i=0;i<mp[t].size();i++)
		{
			int now=mp[t][i];
			indegree[now]--;
			if(!indegree[now]) q.push(now);
		}
	}
}
int main()
{
	int n,m,a,b,i;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			indegree[i]=0;
			mp[i].clear();
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[b].pb(a);
			indegree[a]++;
		}
		cnt=n;
		topsort(n);
		for(i=1;i<=n;i++)
		{
			if(i==n) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}