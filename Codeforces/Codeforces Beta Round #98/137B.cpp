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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int main()
{
	int n,a,i,maxx,cnt,ans;
	while(~scanf("%d",&n))
	{
		map<int,int> mp;
		maxx=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			mp[a]++;
			maxx=max(maxx,a);
		}
		cnt=ans=0;
		for(i=1;i<=n;i++)
		{
			if(mp[i]>1) ans+=mp[i]-1;
			cnt+=mp[i];
		}
		if(cnt==n) printf("%d\n",ans);
		else printf("%d\n",ans+n-cnt);
	}
    return 0;
}