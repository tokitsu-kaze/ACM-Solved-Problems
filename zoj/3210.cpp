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
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,i,n,a[111],b[111],s,q;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			mem(a,0);
			mem(b,0);
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
			for(i=0;i<n;i++)
			{
				scanf("%d",&b[i]);
			}
			s=q=1;
			for(i=0;i<n;i++)
			{
				if(a[i]!=b[i])
				{
					q=0;
					break;
				}
			}
			reverse(a,a+n);
			for(i=0;i<n;i++)
			{
				if(a[i]!=b[i])
				{
					s=0;
					break;
				}
			}
			if(s&&q) puts("both");
			else if(s) puts("stack");
			else if(q) puts("queue");
			else puts("neither");
		}
	}
	return 0;
}