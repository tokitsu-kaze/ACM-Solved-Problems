////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 23:05:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1027
////Problem Title: 
////Run result: Accept
////Run time:46MS
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
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,m,i,a[1010];
	while(cin>>n>>m)
	{
		mem(a,0);
		for(i=1;i<=n;i++)
		{
			a[i]=i;
		}
		for(i=0;i<m-1;i++)
		{
			next_permutation(a+1,a+1+n);
		}
		for(i=1;i<=n;i++)
		{
			printf("%d",a[i]);
			if(i!=n) printf(" ");
			else puts(""); 
		}
	}
    return 0;
}