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
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int n,flag;
int pre[2111];
int num[2111];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		num[i]=0;
		pre[i]=i;
	}
}
int find(int x)
{
	int temp;
	if(pre[x]!=x)
	{
		temp=pre[x];
		pre[x]=find(pre[x]);
		num[x]=(num[x]+num[temp])%2;
	}
	return pre[x];
}
void merge(int a,int b)
{
	int ra,rb;
	ra=find(a);
	rb=find(b);
	if(ra==rb)
	{
		if(num[a]==num[b]) flag=1;
	}
	else if(ra!=rb)
	{
		pre[ra]=rb;
		num[ra]=(num[a]+num[b]+1)%2;
	}
}
int main()
{
	int t,m,cas=1,a,b;
    scanf("%d",&t);
    {
		while(t--)
		{
			scanf("%d%d",&n,&m);
			init();
			flag=0;
			while(m--)
			{
				scanf("%d%d",&a,&b);
				if(flag) continue;
				merge(a,b);
			}
			printf("Scenario #%d:\n",cas++);
			if(flag) puts("Suspicious bugs found!");
			else puts("No suspicious bugs found!");
			puts("");
		}
    }
    return 0;
}