////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-05 20:00:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3279
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1668KB
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
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=10000;
int main()
{
	int t,i,a[22],cas;
	scanf("%d",&t);
	while(t--)
	{
		mem(a,0);
		scanf("%d",&cas);
		for(i=0;i<10;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+10);
		printf("%d %d\n",cas,a[7]);
	}
	return 0;
}
