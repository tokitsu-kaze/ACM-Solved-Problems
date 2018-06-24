////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-06 20:40:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2569
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
#define MAX 100000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
    ll t,n,i,a[40];
    a[1]=3;
    a[2]=9;
	for(i=3;i<=39;i++)
	{
		a[i]=2*a[i-1]+a[i-2];
	}
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			cout<<a[n]<<endl;
		}
	}
    return 0;
}