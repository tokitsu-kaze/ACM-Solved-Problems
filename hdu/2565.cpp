////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 10:43:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2565
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1572KB
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
int main()
{
    int t,n,i,j,flag;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
			{
				for(j=0,flag=0;j<n;j++)
				{
					if(j==i||j==n-1-i)
					{
						cout<<'X';
						flag++;
					}
					else cout<<' ';
					if(flag==2||(i==n/2&&flag==1)) break;
				}
				puts("");
			}
			puts("");
		}
	}
    return 0;
}
