////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-15 19:58:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4857
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:4668KB
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
const int MAX=30000+10;
const ll mod=1e6;
vector<int> v[MAX];
int n,ans[MAX],k;
int indegree[MAX];
void init()
{
	mem(indegree,0);
	mem(ans,0);
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
	}
}
void topsort()
{
	int i,t;
	priority_queue<int,vector<int>,less<int> > q;
	k=0;
	for(i=1;i<=n;i++)
	{
		if(!indegree[i]) q.push(i);
	}
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		ans[k++]=t;
		for(i=0;i<v[t].size();i++)
		{
			int to=v[t][i];
			indegree[to]--;
			if(!indegree[to]) q.push(to);
		} 
	}
}
int main()
{
	int t,m,a,b,i;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			init();
			scanf("%d%d",&n,&m);
			while(m--)
			{
				scanf("%d%d",&a,&b);
				v[b].push_back(a);
				indegree[a]++;
			}
			topsort();
			for(i=k-1;i>=0;i--)
			{
				if(!i) printf("%d",ans[i]);
				else printf("%d ",ans[i]);
			}
			puts("");
		}
	}
	return 0;
}