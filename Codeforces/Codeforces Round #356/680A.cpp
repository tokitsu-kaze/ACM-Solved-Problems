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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e6;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int a[11],cnt[111],i,ans,now;
	while(~scanf("%d",&a[0]))
	{
		ans=a[0];
		mem(cnt,0);
		cnt[a[0]]++;
		for(i=1;i<5;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			ans+=a[i];
		}
		now=ans;
		sort(a,a+5,cmp);
		for(i=0;i<5;i++)
		{
			if(cnt[a[i]]==2||cnt[a[i]]==3)
			{
				ans=min(ans,now-a[i]*cnt[a[i]]);
			}
			else if(cnt[a[i]]>3)
			{
				ans=min(ans,now-a[i]*3);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}