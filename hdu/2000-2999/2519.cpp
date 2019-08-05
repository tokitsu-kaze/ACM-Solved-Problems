////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 21:58:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2519
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1588KB
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
typedef long long ll;
int main()
{
	int t,n,m,i,j;
	double a,b;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m;
			a=b=1;
			for(i=0;i<m;i++)
			{
				a*=(n-i);
			}
			for(j=0;j<m;j++)
			{
				b*=(m-j);
			}
			printf("%.0lf\n",a/b);
		}
	}
    return 0;
}