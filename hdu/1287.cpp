////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-05 17:04:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1287
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=1e5+10;
int main()
{
	int n,v[1111],i,j;
	char ans[1111];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		mem(ans,0);
		for(i='A';i<='Z';i++)
		{
			int flag=0;
			for(j=0;j<n;j++)
			{
				ans[j]=i^v[j];
				if(ans[j]<'A'||ans[j]>'Z')
				{
					flag=1;
					break;
				}
			}
			if(!flag) break;
		}
		ans[n]='\0';
		puts(ans);
	}
	return 0;
}