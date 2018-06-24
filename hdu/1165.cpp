////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-03 18:03:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1165
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:1608KB
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
ll A(ll m,ll n)
{
	if(n==0) return A(m-1,1);
	if(m==0) return n+1;
	if(m==1) return n+2;
	if(m==2) return A(m,n-1)+2;
	if(m==3) return A(m,n-1)*2+3;
}
int main()
{
	ll m,n;
	while(cin>>m>>n)
	{
		cout<<A(m,n)<<endl;
	}
    return 0;
}