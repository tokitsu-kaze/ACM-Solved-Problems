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
	int a,b;
}a[MAX];
int main()
{
	int n,time,i,sum,ans[MAX],temp;
	while(~scanf("%d%d",&n,&time))
	{
		sum=temp=0;
		mem(ans,0);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].a,&a[i].b);
			temp+=a[i].a;
			sum+=a[i].b;
			ans[i]=a[i].a;
		}
		if(sum<time||temp>time)
		{
			puts("NO");
			continue;
		}
		else puts("YES");
		sum=temp;
		for(i=0;i<n;i++)
		{
			temp=a[i].b-a[i].a;
			if(sum+temp<time)
			{
				ans[i]=a[i].b;
				sum+=temp;
			}
			else
			{
				ans[i]+=time-sum;
				sum=time;
			}
			if(sum==time) break;
		}
		for(i=0;i<n;i++)
		{
			if(!i) printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		}
		puts("");
	}
	return 0;
}
/*
2 5
2 3
1 4
*/