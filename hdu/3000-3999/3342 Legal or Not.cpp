////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-13 18:30:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3342
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1624KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 100000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int mp[111][111];
int in_degree[111];
int n,cnt;
void topsort()
{
	int i,t;
	queue<int> q;
	for(i=0;i<n;i++)
	{
		if(!in_degree[i]) q.push(i);
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		cnt++;
		for(i=0;i<n;i++)
		{
			if(mp[t][i])
			{
				in_degree[i]--;
				if(!in_degree[i]) q.push(i);
			}
		}
	}
}
int main()
{
	int m,i,a,b;
	while(~scanf("%d%d",&n,&m)&&(n+m))
	{
		mem(mp,0);
		mem(in_degree,0);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			if(!mp[a][b])
			{
				mp[a][b]=1;
				in_degree[b]++;
			}
		}
		cnt=0;
		topsort();
		if(cnt==n) puts("YES");
		else puts("NO");
	}
    return 0;
}