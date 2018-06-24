////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-29 19:00:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4696
////Problem Title: 
////Run result: Accept
////Run time:280MS
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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,i,x,flag;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
		}
		flag=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==1) flag=1;
		}
		while(m--)
		{
			scanf("%d",&x);
			if(x<=0) puts("NO");
			else if(flag||x%2==0) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}