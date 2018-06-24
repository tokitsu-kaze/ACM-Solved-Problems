////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 14:12:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2824
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:25088KB
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
#define MAX 3000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
ll ans[MAX];
void euler()
{
	ll i,j;
	ans[1]=0;
	for(i=2;i<MAX;i++)
	{
		ans[i]=i;
	}
	for(i=2;i<MAX;i++)
	{
		if(ans[i]==i)
		{
			for(j=i;j<MAX;j+=i)
			{
				ans[j]=ans[j]-ans[j]/i;
			}
		}
	}
	for(i=2;i<MAX;i++)
	{
		ans[i]+=ans[i-1];
	}
}
int main()
{
    ll a,b;
    euler();
    while(cin>>a>>b)
    {
		cout<<ans[b]-ans[a-1]<<endl;
	}
    return 0;
}