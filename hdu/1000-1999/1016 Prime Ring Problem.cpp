////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-09 21:34:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:1616KB
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
typedef long long ll;
int prime[40];
int n,flag[21];
map<int,int>m;
void dfs(int row)
{
	int i;
	if(row==n)
	{
		if(prime[flag[n]+1])
		{
			for(i=1;i<=n;i++)
			{
				cout<<flag[i];
				if(i!=n) cout<<" ";
				else puts("");
			}
		}
		return;
	}
	for(i=2;i<=n;i++)
	{
		if(!m[i]&&prime[i+flag[row]])
		{
			m[i]=1;
			flag[row+1]=i;
			dfs(row+1);
			m[i]=0;
			flag[row+1]=0;
		}
	}
	return;
}
int main()
{
    int cas=1,i,j;
    fill(prime+2,prime+40,1);
    for(i=2;i<40;i++)
    {
		if(prime[i])
		{
			for(j=i+i;j<40;j+=i)
			{
				prime[j]=0;
			}
		}
	}
	while(cin>>n)
	{
		m.clear();
		printf("Case %d:\n",cas++);
		mem(flag,0);
		m[1]=1;
		flag[1]=1;
		dfs(1);
		puts("");
	} 
    return 0;
}
