////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-09 22:09:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5494
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1676KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=100000+10;
const ll mod=10000;
int main()
{
	int t,i,n,m,a[511],b[511],c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+n);
		c=d=0;
		for(i=0;i<m;i++)
		{
			c+=a[i];
		}
		for(i=n-1;i>=n-m;i--)
		{
			d+=b[i];
		}
		if(c>d) puts("YES");
		else puts("NO");
	}
	return 0;
}