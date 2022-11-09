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
	int n,m,k,i,a[111],ans; 
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		mem(a,0);
		ans=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=m;i>=1;i--)
		{
			if(a[i]<=k&&a[i])
			{
				ans=min(ans,abs(m-i)*10);
				break;
			}
		}
		for(i=m;i<=n;i++)
		{
			if(a[i]<=k&&a[i])
			{
				ans=min(ans,abs(m-i)*10);
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}