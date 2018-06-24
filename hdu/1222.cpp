////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-03 18:21:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1222
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
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
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef __int64 ll;
//typedef long long ll;
ll gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
	ll t,m,n;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>m>>n;
			if(gcd(m,n)==1) puts("NO");
			else puts("YES");	
		}
	}
    return 0;
}