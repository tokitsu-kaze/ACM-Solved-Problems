////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-10 14:36:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2203
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1884KB
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
typedef double LD;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
char a[200010],b[100010],c[100010];
int main()
{
	while(~scanf("%s%s",a,b))
	{
		strcpy(c,a);
		strcat(a,c);
		if(strstr(a,b)) puts("yes");
		else puts("no");
	}
	return 0;
}