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
struct node
{
	int id,v;
}a[111];
bool cmp(node a,node b)
{
	return a.v>b.v;
}
int main()
{
	int t,i,n;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			mem(a,0);
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i].v);
				a[i].id=i+1;
			}
			sort(a,a+n,cmp);
			printf("%d %d\n",a[0].id,a[1].v);
		}
	}
	return 0;
}