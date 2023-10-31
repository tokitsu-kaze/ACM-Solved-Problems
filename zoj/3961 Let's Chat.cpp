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
struct point
{
	int x,y;
	void input()
	{
		scanf("%d%d",&x,&y);
	}
}a[MAX],b[MAX],ans[MAX*MAX];
int main()
{
	int t,n,m,x,y,i,j,k,s;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d%d",&n,&m,&x,&y);
			for(i=0;i<x;i++)
			{
				a[i].input();
			}
			for(i=0;i<y;i++)
			{
				b[i].input();
			}
			k=0;
			for(i=0;i<x;i++)
			{
				for(j=0;j<y;j++)
				{
					if(b[j].x<=a[i].x&&b[j].y>=a[i].x&&b[j].y<=a[i].y)
					{
						ans[k].x=a[i].x;
						ans[k].y=b[j].y;
						k++;
					}
					else if(b[j].x>=a[i].x&&b[j].y<=a[i].y)
					{
						ans[k].x=b[j].x;
						ans[k].y=b[j].y;
						k++;
					}
					else if(b[j].x>=a[i].x&&a[i].y>=b[j].x&&a[i].y<=b[j].y)
					{
						ans[k].x=b[j].x;
						ans[k].y=a[i].y;
						k++;
					}
					else if(b[j].x<=a[i].x&&b[j].y>=a[i].y)
					{
						ans[k].x=a[i].x;
						ans[k].y=a[i].y;
						k++;
					}
				}
			}
	//		cout<<k<<endl;
			s=0;
			for(i=0;i<k;i++)
			{
	//			cout<<ans[i].x<<" "<<ans[i].y<<"*"<<endl;
				if(ans[i].y-ans[i].x+1-m+1>0) s+=ans[i].y-ans[i].x+1-m+1;
			}
			printf("%d\n",s);
		}
	}
	return 0;
}
/*
3
10 3 3 2
1 3
5 8
10 10
1 8
10 10

10 3 2 3
1 8
10 10
1 3
5 8
10 10

5 3 1 1
1 2
4 5

1
5 2 1 3
1 5
1 2
3 3
4 5
*/