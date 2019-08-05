////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-06 19:48:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:2756KB
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
int pre[MAX],pa[2*MAX];
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
    int a,b,k,i,cnt,flag;
    while(1)
    {
		for(i=1;i<=MAX;i++)
		{
			pre[i]=i;
		}
		cnt=k=0;
		mem(pa,0);
		flag=0;
		while(cin>>a>>b&&(a+b))
		{
			if(a==-1&&b==-1) return 0;
			pa[k++]=a;
			pa[k++]=b;
			if(!Union(a,b)) flag=1;
		}
		if(flag)
		{
			puts("No");
			continue;
		}
		for(i=1,flag=0;i<k&&!flag;i++)
		{
			if(find(pa[i])!=find(pa[0])) flag=1;
		}
		if(flag) puts("No");
		else puts("Yes");
    }
    return 0;
}