////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-08 22:06:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
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
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int mp[111][111];
int dis[111];
int flag[111];
int ans,n,flag1;
void prim(int s)
{
	int i,j,min,temp;
	dis[s]=0;
	flag[s]=1;
	for(i=1;i<=n;i++)
	{
		dis[i]=mp[1][i];
	}
	for(i=2;i<=n;i++)
	{
		min=INF;
		for(j=1;j<=n;j++)
		{
			if(!flag[j]&&dis[j]<min)
			{
				min=dis[j];
				temp=j;
			}
		}
		if(min==INF)
		{
			puts("?");
			flag1=1;
			return;
		}
		else
		{
			ans+=dis[temp];
			flag[temp]=1;
		}
		for(j=1;j<=n;j++)
		{
			if(dis[j]>mp[temp][j]) dis[j]=mp[temp][j];
		}
	}
}
int main()
{
	int m,a,b,c;
	while(~scanf("%d%d",&m,&n)&&m)
	{
		mem(dis,0x3f);
		mem(mp,0x3f);
		mem(flag,0);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(mp[a][b]>c) mp[a][b]=mp[b][a]=c;
		}
		ans=0;
		flag1=0;
		prim(1);
		if(!flag1) printf("%d\n",ans);
	}
	return 0;
}