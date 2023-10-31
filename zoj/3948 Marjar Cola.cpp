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
int main()
{
	int t,x,y,a,b,ans,temp;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d%d",&x,&y,&a,&b);
			if(x==1||y==1||(x==2&&y==2&&a+b>=3))
			{
				puts("INF");
				continue;
			}
			ans=0;
			while(a/x||b/y)
			{
				temp=a/x+b/y;
				ans+=temp;
				a=a%x+temp;
				b=b%y+temp;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}