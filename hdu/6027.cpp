////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-09 15:45:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6027
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1560KB
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
	ll i,j,n,k,s,t,temp;
	while(~scanf("%lld",&t))
	{
		while(t--)
		{
			scanf("%lld%lld",&n,&k);
			s=0;
			for(i=1;i<=n;i++)
			{
				temp=1;
				for(j=0;j<k;j++)
				{
					temp*=i;
					temp%=mod;
				}
				s+=temp;
				s%=mod;
			}
			s%=mod;
			printf("%lld\n",s);
		}
	}
	return 0;
}