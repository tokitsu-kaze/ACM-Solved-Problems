////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-06 20:17:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1325
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:3160KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int pre[MAX],pa[2*MAX],in_degree[MAX];
int find(int x)
{
	if(pre[x]==x) return x;
	else return find(pre[x]);
}
int Union(int a,int b)
{
	int ta,tb;
	ta=find(a);
	tb=find(b);
	if(ta!=tb)
	{
		pre[ta]=tb;
		return 1;
	}
	return 0;
}
int main()
{
    int a,b,k,i,cas=1,flag;
    while(1)
    {
		for(i=1;i<=MAX;i++)
		{
			pre[i]=i;
		}
		k=0;
		mem(pa,0);
		mem(in_degree,0);
		flag=0;
		while(cin>>a>>b&&(a+b))
		{
			if(a<0||b<0) return 0;
			pa[k++]=a;
			pa[k++]=b;
			if(!Union(a,b)) flag=1;
		}
		printf("Case %d ",cas++);
		if(flag)
		{
			puts("is not a tree.");
			continue;
		}
		for(i=1;i<=k;i+=2)
		{
			if(!Union(pa[i-1],pa[i])) in_degree[pa[i]]++;
		}
		for(i=1,flag=0;i<k&&!flag;i++)
		{
			if(find(pa[i])!=find(pa[0])) flag=1;
			if(in_degree[pa[i]]>1) flag=1;
		}
		if(flag) puts("is not a tree.");
		else puts("is a tree.");
    }
    return 0;
}