////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-10 14:57:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2270
////Problem Title: 
////Run result: Accept
////Run time:436MS
////Run memory:5584KB
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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=1e6+10;
int pre[MAX];
int main()
{
	int n,i,a,cnt;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(pre[a]!=pre[i]) pre[a]=pre[i];
		}
		cnt=0;
		for(i=2;i<=n;i++)
		{
			if(pre[i]==pre[1]) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
/*
4
2
1
1
3
*/