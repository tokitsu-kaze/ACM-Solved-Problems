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
struct node
{
	int l,w,flag;
}a[5010];
bool cmp(node a,node b)
{
	if(a.l==b.l) return a.w<b.w;
	return a.l<b.l;
}
int main()
{
	int t,n,i,j,cnt,flag;
	node temp;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&a[i].l,&a[i].w);
				a[i].flag=0;
			}
			sort(a,a+n,cmp);
			cnt=0;
			flag=0;
			while(flag<n)
			{
				temp.l=-1;
				temp.w=-1;
				cnt++;
				for(i=0;i<n;i++)
				{
					if(flag==n) break;
					if(a[i].flag) continue;
					if(a[i].l>=temp.l&&a[i].w>=temp.w)
					{
						a[i].flag=1;
						flag++;
						temp=a[i];
					}
				}
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}