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
	ll n,x,i,a[MAX],t,ans;
	while(~scanf("%lld%lld",&n,&x))
	{
		mem(a,0);
		t=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ans=0;
		if(a[0]>x)
		{
			t=a[0]-x;
			ans+=t;
			a[0]-=t;
		}
		for(i=1;i<n;i++)
		{
			if(a[i]+a[i-1]>x)
			{
				t=a[i]+a[i-1]-x;
				ans+=t;
				a[i]-=t;
			}
		}
	//	if(a[n-2]+a[n-1]>x) ans+=a[n-2]+a[n-1]-x;
		printf("%lld\n",ans);
	}
	return 0;
}
