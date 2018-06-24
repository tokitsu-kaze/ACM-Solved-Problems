////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-02 22:49:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2553
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int sum,line[11],t;
void dfs(int row) 
{
	int i,j,flag;
	if(row==t+1) sum++;
	else
	{
		for(i=1;i<=t;i++)
		{
			line[row]=i;
			for(j=1,flag=1;j<row;j++)
			{
				if(line[row]==line[j]||line[row]-row==line[j]-j||line[row]+row==line[j]+j)
				{
					flag=0;
					break;
				}
			}
			if(flag) dfs(row+1);
		//	cout<<sum<<endl;
		}
	}
}
int main()
{
    int n,a[11];
    mem(a,0);
    for(t=1;t<=10;t++)
	{
		sum=0;
		dfs(1);
		a[t]=sum;
	}
    while(cin>>n&&n)
    {
		cout<<a[n]<<endl;
	}
    return 0;
}
