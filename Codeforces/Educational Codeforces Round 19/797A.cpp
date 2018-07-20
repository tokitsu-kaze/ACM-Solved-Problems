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
	int n,k,ans[11111],cnt,i;
	while(~scanf("%d%d",&n,&k))
	{
		cnt=0;
		mem(ans,0);
		for(i=2;i<=n&&k!=1;i++)
		{
			while(n%i==0)
			{
				ans[cnt++]=i;
				n/=i;
				k--;
				if(k==1) break;
			}
		}
		if(k!=1||n==1) puts("-1");
		else
		{
			ans[cnt++]=n;
			for(i=0;i<cnt;i++)
			{
				if(!i) printf("%d",ans[i]);
				else printf(" %d",ans[i]);
			}
			puts("");
		}
	} 
	return 0;
}