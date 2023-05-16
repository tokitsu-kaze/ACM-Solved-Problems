////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-06 18:31:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:31MS
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
    int n,m,i,a,b,ans;
    while(cin>>n&&n)
    {
		cin>>m;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
		}
		ans=n-1;
		while(m--)
		{
			scanf("%d%d",&a,&b);
			if(Union(a,b)) ans--;
		}
		cout<<ans<<endl;
    }
    return 0;
}