////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-10 14:55:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1338
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1680KB
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
int main()
{
	int n,m,a[55],i,j,ans,cnt,cas=1;
	while(~scanf("%d%d",&m,&n)&&n&&m)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		ans=cnt=0;
		for(i=n*m,j=n-1;i>=1&&j>=0;i--)
		{
			if(i==a[j])
			{
				cnt++;
				j--;
			}
			else cnt--;
			ans=max(ans,cnt);
		}
		if(ans<0) ans=0;
		printf("Case %d: %d\n",cas++,ans);
	}
	return 0;
}