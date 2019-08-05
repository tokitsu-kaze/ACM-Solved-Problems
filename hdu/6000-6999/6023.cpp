////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-09 16:56:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6023
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1556KB
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
const int MAX=1000000+10;
const ll mod=1e9+7;
int main()
{
	int t,n,k,id,h,m,ac,time;
	char s[11];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&k);
			map<int,int> flag,an;
			ac=time=0;
			while(k--)
			{
				scanf("%d %d:%d %s",&id,&h,&m,s);
				if(flag[id]) continue;
				if(s[0]=='A')
				{
					flag[id]=1;
					ac++;
					time+=h*60+m;
					time+=an[id]*20;
				}
				else an[id]++;
			}
			printf("%d %d\n",ac,time);
		}
	}
	return 0;
}