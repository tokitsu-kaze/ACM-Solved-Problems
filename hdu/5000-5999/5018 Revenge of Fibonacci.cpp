////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-15 21:01:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
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
const double eps=1e-12;
const int MAX=100000+10;
const ll mod=1e6;
int main()
{
	int t;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			int a1,a2,k;
			scanf("%d%d%d",&a1,&a2,&k);
			if(a1==k||a2==k)
			{
				puts("Yes");
				continue;
			}
			int flag=0;
			while(k>a2)
			{
				int t=a2;
				a2+=a1;
				a1=t;
				if(a2==k)
				{
					flag=1;
					break;
				}
			}
			if(flag) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}