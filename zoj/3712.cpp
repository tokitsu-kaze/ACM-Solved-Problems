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
const int MAX=1000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,a,b,c,i,sum1,sum2,s;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d",&a,&b,&c);
			sum1=sum2=0;
			s=-1;
			for(i=0;i<c;i++)
			{
				s++;
				sum2+=50*(s*2+1);
			}
			for(i=0;i<b;i++)
			{
				s++;
				sum2+=100*(s*2+1);
			}
			for(i=0;i<a;i++)
			{
				s++;
				sum2+=300*(s*2+1);
			}
			s=-1;
			for(i=0;i<a;i++)
			{
				s++;
				sum1+=300*(s*2+1);
			}
			for(i=0;i<b;i++)
			{
				s++;
				sum1+=100*(s*2+1);
			}
			for(i=0;i<c;i++)
			{
				s++;
				sum1+=50*(s*2+1);
			}
			printf("%d %d\n",sum1,sum2);
		}
	}
	return 0;
}