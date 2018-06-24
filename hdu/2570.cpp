////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-09 16:39:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2570
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
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
const double eps=1e-9;
const int MAX=100000+10;
const ll mod=10000;
int main()
{
	int t,i,n,v,w,a[111];
	double s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&v,&w);
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		s=0;
		for(i=0;i<n;i++)
		{
			s+=a[i]*v/100.0;
			if(s/(v*(i+1))-w/100.0>eps)
			{
				s-=a[i]*v/100.0;
				break;
			}
		}
		if(i) printf("%d %.2lf\n",i*v,s/(i*v));
		else puts("0 0.00");
	}
	return 0;
}