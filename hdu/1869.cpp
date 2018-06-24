////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-04 11:59:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1869
////Problem Title: 
////Run result: Accept
////Run time:78MS
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,m,a,b,i,j,k,map1[110][110],flag;
	while(cin>>n>>m)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				map1[i][j]=INF;
			}
		}
		while(m--)
		{
			cin>>a>>b;
			map1[a][b]=map1[b][a]=1;
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					map1[i][j]=min(map1[i][j],map1[i][k]+map1[k][j]);
				}
			}
		}
		flag=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(map1[i][j]>7) flag=1;
			}
		}
		if(flag) puts("No");
		else puts("Yes");
	}
    return 0;
}