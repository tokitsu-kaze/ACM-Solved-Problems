////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-28 15:53:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1257
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2368KB
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
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
	int t,n,a[MAX],flag[MAX],cnt,i,j,pre;
	while(cin>>n)
	{
		cnt=0;
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			if(!flag[i])
			{
				pre=a[i];
				cnt++;
				for(j=i+1;j<n;j++)
				{
					if(a[j]<=pre&&!flag[j])
					{
						flag[j]=1;
						pre=a[j];
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}