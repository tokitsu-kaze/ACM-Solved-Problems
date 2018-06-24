////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 21:25:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2156
////Problem Title: 
////Run result: Accept
////Run time:514MS
////Run memory:1584KB
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
	int n,i,j;
	double sum;
	while(cin>>n&&n)
	{
		sum=0;
		for(i=n,j=1;i>1;i--,j++)
		{
			sum+=1.0/i*j;
		}
		printf("%.2lf\n",2*sum+n);
	}
    return 0;
}