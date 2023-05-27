////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-01-22 14:49:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2135
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    int n,m,i,j;
    char a[13][13];
    while(cin>>n>>m)
    {
		mem(a,0);
		getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%c",&a[i][j]);
			}
			getchar();
		}
		m%=4;
		if(m==1||m==-3)
		{
			for(i=0;i<n;i++)
			{
				for(j=n-1;j>=0;j--)
				{
					cout<<a[j][i];
				}
				puts("");
			}
		}
		else if(m==-1||m==3)
		{
			for(i=n-1;i>=0;i--)
			{
				for(j=0;j<n;j++)
				{
					cout<<a[j][i];
				}
				puts("");
			}
		}
		else if(m==2||m==-2)
		{
			for(i=n-1;i>=0;i--)
			{
				for(j=n-1;j>=0;j--)
				{
					cout<<a[i][j];
				}
				puts("");
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					cout<<a[i][j];
				}
				puts("");
			}
		}
	}
    return 0;
}
/*
7 4 1
8 5 2
9 6 3*/