////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-04 18:27:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2181
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1576KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
vector<int> v[22];
int cnt,flag[22],ans[22];
void init()
{
	int i;
	for(i=0;i<=20;i++)
	{
		v[i].clear();
	}
}
void dfs(int r,int e,int k)
{
	int i;
	if(k==20&&r==e)
	{
		printf("%d:  %d",cnt++,e);
		for(i=0;i<20;i++)
		{
			printf(" %d",ans[i]);
		}
		puts("");
	}
	for(i=0;i<v[r].size();i++)
	{
		if(flag[v[r][i]]==0)
		{
			flag[v[r][i]]=1;
			ans[k]=v[r][i];
			dfs(v[r][i],e,k+1);
			flag[v[r][i]]=0;
		}
	}
}
int main()
{
	int a[3],i,m;
	init();
	for(i=1;i<=20;i++)
	{
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3); 
		v[i].push_back(a[0]);
		v[i].push_back(a[1]);
		v[i].push_back(a[2]);
	}
	while(~scanf("%d",&m)&&m)
	{
		cnt=1;
		mem(flag,0);
		mem(ans,0);
		dfs(m,m,0);
	}
	return 0;
}