////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-04 22:05:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2510
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1564KB
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
/*
int a[33][33];
int sum[33];
void dfs(int n,int i)
{
	int j,k,temp,sum1=0,sum2=0;
	if(i<=n)
	{
		a[1][i]=0;
		dfs(n,i+1);
	}
	else
	{
		for(j=2;j<=n;j++)
		{
			for(k=1;k<=n+1-j;k++)
			{
				temp=a[j-1][k]+a[j-1][k+1];
				a[j][k]=temp%2;
			}
		}
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n+1-j;k++)
			{
				if(a[j][k]) sum1++;
				else sum2++;
			}
		}
		if(sum1==sum2) sum[n]++;
		return;
	}
	a[1][i]=1;
	dfs(n,i+1);
	return;
}*/
int main()
{
/*	int i,j;
	for(i=1;i<=24;i++)
	{
		dfs(i,1);
		printf("%d\n", sum[i]);
	}*/
	int a[]={0,0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229};
	int n;
	while(~scanf("%d",&n)&&n)
	{
		printf("%d %d\n",n,a[n]);
	}
	return 0;
}