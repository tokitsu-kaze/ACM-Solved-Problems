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
#define MAX 10000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int n;
int pre[30010];
int num[30010];
void init()
{
	int i;
	for(i=0;i<=n;i++)
	{
		pre[i]=i;
		num[i]=1;
	}
}
int find(int x)
{
	int temp;
	if(pre[x]!=x)
	{
		temp=pre[x];
		pre[x]=find(pre[x]);
		pre[x]=pre[temp];
	}
	return pre[x];
}
void merge(int a,int b)
{
	int ta,tb;
	ta=find(a);
	tb=find(b);
	if(ta!=tb)
	{
		pre[ta]=tb;
		num[tb]+=num[ta];
	}
}
int main()
{
	int m,t,a,b;
	while(~scanf("%d%d",&n,&m)&&(m+n))
	{
		init();
		while(m--)
		{
			scanf("%d%d",&t,&a);
			t--;
			while(t--)
			{
				scanf("%d",&b);
				merge(a,b);
				a=b;
			}
		}
		printf("%d\n",num[find(0)]);
	}
	return 0;
}