////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-06 19:16:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1213
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1604KB
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
#define MAX 1000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int pre[1111];
int find(int x)
{
	if(pre[x]==x) return x;
	else return find(pre[x]);
}
int Union(int a,int b)
{
	int ta,tb;
	ta=find(a);
	tb=find(b);
	if(ta!=tb)
	{
		pre[ta]=tb;
		return 1;
	}
	return 0;
}
int main()
{
    int t,n,m,a,b,ans,i;
    while(cin>>t)
    {
		while(t--)
		{
			scanf("%d%d",&n,&m);
			ans=n-1;
			for(i=1;i<=n;i++)
			{
				pre[i]=i;
			}
			while(m--)
			{
				scanf("%d%d",&a,&b);
				if(Union(a,b)) ans--;
			}
			printf("%d\n",ans+1);
		}
    }
    return 0;
}