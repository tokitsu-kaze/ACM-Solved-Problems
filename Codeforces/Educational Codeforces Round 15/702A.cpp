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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int n,i,cnt,ans,a,temp;
	while(~scanf("%d",&n))
	{
		cnt=ans=1;
		scanf("%d",&a);
		temp=a;
		for(i=1;i<n;i++)
		{
			scanf("%d",&a);
			if(a>temp) cnt++;
			else
			{
				ans=max(ans,cnt);
				cnt=1;
			}
			temp=a;
		}
		ans=max(ans,cnt);
		printf("%d\n",ans);
	}
	return 0;
}