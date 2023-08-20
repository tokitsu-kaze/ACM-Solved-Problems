////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-07 16:18:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5533
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1596KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
double cal(double a,double b,double c,double d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main()
{
	int t,n,i,j,cnt;
	double b[5][5],a[111][2],m;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			mem(a,0);
			for(i=0;i<n;i++)
			{
				scanf("%lf%lf",&a[i][0],&a[i][1]);
			}
			if(n!=4)
			{
				puts("NO");
				continue;
			}
			mem(b,0);
			m=(double)INF;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					b[i][j]=cal(a[i][0],a[i][1],a[j][0],a[j][1]);
					m=min(m,b[i][j]);
				}
			}
			cnt=0;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(b[i][j]==m) cnt++;
				}
			}
			if(cnt==4) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}