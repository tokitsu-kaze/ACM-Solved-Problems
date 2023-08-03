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
int a[MAX],flag[MAX];
int main()
{
	int n,m,k,i,ans,l,r,t,tag; 
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		mem(a,0);
		mem(flag,0);
		tag=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&t);
			flag[t]=1;
		}
		a[1]=1;
		ans=1;
		if(flag[1]) tag=1;
		while(k--)
		{
			scanf("%d%d",&l,&r);
			if(tag) continue;
			swap(a[l],a[r]);
			if(a[r])
			{
				ans=r;
				if(flag[r]) tag=1;
			}
			else if(a[l])
			{
				ans=l;
				if(flag[l]) tag=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}